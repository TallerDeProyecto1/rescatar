package unlp.barcala.rescatarapp.utils;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

import unlp.barcala.rescatarapp.services.SmsReceiverService;

/**
 * Created by basti
 * On 23/11/2015.
 */
public class BootReceiver extends BroadcastReceiver {

    @Override
    public void onReceive(Context context, Intent intent) {
        Intent newIntent = new Intent(context, SmsReceiverService.class);
        context.startService(newIntent);
    }
}
