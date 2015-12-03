package unlp.barcala.rescatarapp.model;

/**
 * Created by basti
 * On 16/11/2015.
 */
public class RescatarMessage {

    private double lat;
    private double lon;
    private String sender;
    private String date;
    private MessageState state;

    public RescatarMessage(double lat, double lon, String sender, String date) {
        this.lat = lat;
        this.lon = lon;
        this.sender = sender;
        this.date = date;
        this.state = MessageState.ONGOING;
    }

    public RescatarMessage(double lat, double lon, String sender, String date, MessageState state) {
        this.lat = lat;
        this.lon = lon;
        this.sender = sender;
        this.date = date;
        this.state = state;
    }

    public double getLat() {
        return lat;
    }

    public double getLon() {
        return lon;
    }

    public String getSender() {
        return sender;
    }

    public String getDate() {
        return date;
    }

    public MessageState getState(){return state;}

    public void setState (MessageState newState){this.state = newState;}


    public enum MessageState{
        ONGOING,HANDLED,PROCESSING;
    }
}
