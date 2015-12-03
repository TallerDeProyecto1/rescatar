package unlp.barcala.rescatarapp.utils;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

import unlp.barcala.rescatarapp.model.RescatarMessage;

/**
 * Created by basti
 * On 21/11/2015.
 */
public class JsonConverter {

    public String rescaterMessagesToJsonString(List<RescatarMessage> messages) {
        JSONArray arrayMessages = new JSONArray();
        for (RescatarMessage message : messages) {
            JSONObject object = new JSONObject();
            try {
                object.put("lat", message.getLat());
                object.put("lon", message.getLon());
                object.put("sender", message.getSender());
                object.put("date", message.getDate());
                object.put("state", message.getState());
            } catch (JSONException e) {
                e.printStackTrace();
            }
            arrayMessages.put(object);
        }
        return arrayMessages.toString();
    }

    public List<RescatarMessage> jsonToRescatarMessageList(String json) {
        List<RescatarMessage> messageList = new ArrayList<>();
        try {
            JSONArray arrayMessage = new JSONArray(json);
            for (int i = 0; i < arrayMessage.length(); i++) {
                JSONObject object = arrayMessage.getJSONObject(i);
                double lat = object.getDouble("lat");
                double lon = object.getDouble("lon");
                String sender = object.getString("sender");
                String date = object.getString("date");
                RescatarMessage message = new RescatarMessage(lat,lon,sender,date);
                messageList.add(message);
            }
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return messageList;
    }

}
