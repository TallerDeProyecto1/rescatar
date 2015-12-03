package unlp.barcala.rescatarapp.utils;

import android.content.Context;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;

/**
 * Created by basti
 * On 23/11/2015.
 */
public class SavedPreferences {

    private static final String PREF_HISTORIC = "PREF_HISTORIC";

    private static SharedPreferences getPreferences(Context context){
        return PreferenceManager.getDefaultSharedPreferences(context);
    }

    public static void setPrefHistoric(Context calling, String historic){
        SharedPreferences preferences = getPreferences(calling);
        SharedPreferences.Editor editor = preferences.edit();
        editor.putString(PREF_HISTORIC,historic);
        editor.apply();
    }

    public static String getPrefHistoric(Context calling){
        SharedPreferences preferences = getPreferences(calling);
        return preferences.getString(PREF_HISTORIC,"empty historic");
    }

}
