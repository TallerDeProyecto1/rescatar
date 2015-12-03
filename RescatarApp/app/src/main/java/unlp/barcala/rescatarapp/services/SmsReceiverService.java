package unlp.barcala.rescatarapp.services;

import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.app.TaskStackBuilder;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.os.IBinder;
import android.support.v4.app.NotificationCompat;
import android.telephony.SmsMessage;
import android.util.Log;

import java.util.ArrayList;
import java.util.List;

import unlp.barcala.rescatarapp.R;
import unlp.barcala.rescatarapp.Rescatar;
import unlp.barcala.rescatarapp.activities.DisplayActivity;
import unlp.barcala.rescatarapp.model.RescatarMessage;
import unlp.barcala.rescatarapp.utils.JsonConverter;
import unlp.barcala.rescatarapp.utils.SavedPreferences;

public class SmsReceiverService extends Service {

    private NotificationManager notificationManager;
    private JsonConverter jsonConverter;
    public SmsReceiverService() {
    }

    @Override
    public void onCreate() {
        super.onCreate();
        notificationManager = (NotificationManager)getSystemService(NOTIFICATION_SERVICE);
        jsonConverter = new JsonConverter();
        IntentFilter filter = new IntentFilter();
        filter.addAction("android.provider.Telephony.SMS_RECEIVED");
        registerReceiver(receiver,filter);
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        unregisterReceiver(receiver);
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        return super.onStartCommand(intent, flags, startId);
    }

    private final BroadcastReceiver receiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            Log.d("RESCATAR", "Enter the receiver");
            final Bundle bundle = intent.getExtras();
            SmsMessage[] msg;
            String result = "";
            if (bundle != null) {
                Object[] pdus = (Object[]) bundle.get("pdus");
                msg = new SmsMessage[pdus.length];
                for (int i = 0; i < msg.length; i++) {
                    msg[i] = SmsMessage.createFromPdu((byte[]) pdus[i]);
                    result += msg[i].getMessageBody();
                    result +="\n"+msg[i].getDisplayOriginatingAddress();
                }
                Log.d("RESCATAR","Read sms content");
            } else {
                result = "Empty bundle";
            }
            String[] messageDatas = result.split("\n");
            String date = messageDatas[1];
            double lat = Double.parseDouble(messageDatas[2]);
            double lon = Double.parseDouble(messageDatas[3]);
            String sender = messageDatas[4];
            RescatarMessage message= new RescatarMessage(lat,lon,sender,date);
            String historic = SavedPreferences.getPrefHistoric(getApplicationContext());
            List<RescatarMessage> list;
            if(historic.equals("empty historic")){
                list = new ArrayList<>();
            }else{
                 list = jsonConverter.jsonToRescatarMessageList(historic);
            }
            list.add(message);
            SavedPreferences.setPrefHistoric(getApplicationContext(),jsonConverter.rescaterMessagesToJsonString(list));
            sendNotification();
        }
    };

    private void sendNotification(){
        NotificationCompat.Builder mBuilder = new NotificationCompat.Builder(this)
                .setContentTitle("Rescatar Alerta !")
                .setContentText("Occurio un accidente !")
                .setSmallIcon(R.mipmap.ic_launcher);
        Intent resultIntent = new Intent(this,DisplayActivity.class);
        TaskStackBuilder stack = TaskStackBuilder.create(this);
        stack.addParentStack(DisplayActivity.class);
        stack.addNextIntent(resultIntent);
        PendingIntent resultPendingIntent = stack.getPendingIntent(0,PendingIntent.FLAG_UPDATE_CURRENT);
        mBuilder.setContentIntent(resultPendingIntent);
        mBuilder.setAutoCancel(true);
        notificationManager.notify(1, mBuilder.build());
    }
}
