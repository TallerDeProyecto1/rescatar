package unlp.barcala.rescatarapp;

import android.app.Application;

import java.util.ArrayList;
import java.util.List;

import unlp.barcala.rescatarapp.model.RescatarMessage;

/**
 * Created by basti
 * On 16/11/2015.
 */
public class Rescatar extends Application {

    private static List<RescatarMessage> historic = new ArrayList<>();

    @Override
    public void onCreate() {
        super.onCreate();
    }

    public void addMessage(RescatarMessage message){
        historic.add(message);
    }

    public void removeMessage(int i){
        historic.remove(i);
    }

    public List<RescatarMessage> getHistoric(){return historic;}
    public void setHistoric(List<RescatarMessage> newHistoric){
        historic.clear();
        historic.addAll(newHistoric);
    }

    public void setEmptyHistoric(){
        historic = new ArrayList<>();
    }

}
