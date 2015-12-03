package unlp.barcala.rescatarapp.utils;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.telephony.SmsMessage;
import android.util.Log;

/**
 * Created by basti
 * On 09/11/2015.
 */
public class SmsReceiver extends BroadcastReceiver {

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
        //Intent i = new Intent("SMS_RECEIVED").putExtra("message_body",result);
        //context.sendBroadcast(i);
    }
}
