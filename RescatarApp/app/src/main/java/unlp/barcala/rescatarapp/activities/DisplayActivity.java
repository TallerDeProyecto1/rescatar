package unlp.barcala.rescatarapp.activities;

import android.app.ActivityManager;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.support.v4.app.FragmentActivity;
import android.os.Bundle;

import com.google.android.gms.maps.CameraUpdate;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.CameraPosition;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.LatLngBounds;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;

import java.util.ArrayList;
import java.util.List;

import unlp.barcala.rescatarapp.R;
import unlp.barcala.rescatarapp.Rescatar;
import unlp.barcala.rescatarapp.model.RescatarMessage;
import unlp.barcala.rescatarapp.services.SmsReceiverService;
import unlp.barcala.rescatarapp.utils.JsonConverter;
import unlp.barcala.rescatarapp.utils.SavedPreferences;

public class DisplayActivity extends FragmentActivity implements GoogleMap.OnMapLoadedCallback,GoogleMap.OnCameraChangeListener{



    private GoogleMap mMap; // Might be null if Google Play services APK is not available.
    private static Rescatar myApp;
    private JsonConverter myConverter;
    private List<Marker> markers;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_display);
        myApp = new Rescatar();
        myConverter = new JsonConverter();
        markers = new ArrayList<>();
        if(!isMyServiceRunning(SmsReceiverService.class)){
            Intent serviceIntent = new Intent(getApplicationContext(),SmsReceiverService.class);
            startService(serviceIntent);
        }

    }

    @Override
    protected void onResume() {
        super.onResume();
        String hist = SavedPreferences.getPrefHistoric(getApplicationContext());
        if(!hist.equals("empty historic"))
            myApp.setHistoric(myConverter.jsonToRescatarMessageList(hist));
        else
            myApp.setEmptyHistoric();
        setUpMapIfNeeded();
    }

    @Override
    protected void onStop() {
        String hist = myConverter.rescaterMessagesToJsonString(myApp.getHistoric());
        SavedPreferences.setPrefHistoric(getApplicationContext(), hist);
        super.onStop();

    }

    /**
     * This function will check if the asked service is all ready running or not
     * @param serviceClass name of the service
     * @return result
     */
    private boolean isMyServiceRunning(Class<?> serviceClass){
        ActivityManager manager = (ActivityManager) getSystemService(ACTIVITY_SERVICE);
        for(ActivityManager.RunningServiceInfo serviceInfo : manager.getRunningServices(Integer.MAX_VALUE)){
            if(serviceClass.getName().equals(serviceInfo.service.getClassName()))
                return true;
        }
        return false;
    }

    /**
     * Sets up the map if it is possible to do so (i.e., the Google Play services APK is correctly
     * installed) and the map has not already been instantiated.. This will ensure that we only ever
     * call {@link #displayHistoric()} once when {@link #mMap} is not null.
     * <p/>
     * If it isn't installed {@link SupportMapFragment} (and
     * {@link com.google.android.gms.maps.MapView MapView}) will show a prompt for the user to
     * install/update the Google Play services APK on their device.
     * <p/>
     * A user can return to this FragmentActivity after following the prompt and correctly
     * installing/updating/enabling the Google Play services. Since the FragmentActivity may not
     * have been completely destroyed during this process (it is likely that it would only be
     * stopped or paused), {@link #onCreate(Bundle)} may not be called again so we should call this
     * method in {@link #onResume()} to guarantee that it will be called.
     */
    private void setUpMapIfNeeded() {
        // Do a null check to confirm that we have not already instantiated the map.
        if (mMap == null) {
            // Try to obtain the map from the SupportMapFragment.
            mMap = ((SupportMapFragment) getSupportFragmentManager().findFragmentById(R.id.map))
                    .getMap();
            mMap.setOnMapLongClickListener(new GoogleMap.OnMapLongClickListener() {
                @Override
                public void onMapLongClick(LatLng latLng) {
                    for (final Marker marker : markers) {
                        if (Math.abs(marker.getPosition().latitude - latLng.latitude) < 0.05 && Math.abs(marker.getPosition().longitude - latLng.longitude) < 0.05) {
                            new AlertDialog.Builder(DisplayActivity.this)
                                    .setTitle("Quitar accidente")
                                    .setMessage("Quieres quitar este accidente ?")
                                    .setPositiveButton("Si", new DialogInterface.OnClickListener() {
                                        @Override
                                        public void onClick(DialogInterface dialogInterface, int i) {
                                            myApp.removeMessage(markers.indexOf(marker));
                                            marker.remove();
                                            markers.remove(marker);

                                        }
                                    })
                                    .setNegativeButton("No", new DialogInterface.OnClickListener() {
                                        @Override
                                        public void onClick(DialogInterface dialogInterface, int i) {

                                        }
                                    })
                                    .setIcon(android.R.drawable.ic_dialog_alert)
                                    .show();
                        }
                    }

                }
            });
            mMap.setOnMapLoadedCallback(this);

        }
    }

    /**
     * It's here that we display the message all ready received for Rescatar
     */
    private void displayHistoric() {
        List<RescatarMessage> historic = myApp.getHistoric();
        LatLngBounds.Builder builder = new LatLngBounds.Builder();
        for (RescatarMessage msg : historic) {
            Marker newMarker = mMap.addMarker(new MarkerOptions().position(new LatLng(msg.getLat(), msg.getLon())).title(msg.getSender() + " : " + msg.getDate()));
            markers.add(newMarker);
            builder.include(newMarker.getPosition());
        }
        LatLngBounds bounds = builder.build();
        int padding = 80;
        CameraUpdate cu = CameraUpdateFactory.newLatLngBounds(bounds,padding);
        mMap.animateCamera(CameraUpdateFactory.newLatLngZoom(bounds.getCenter(), 3));
//        mMap.moveCamera(CameraUpdateFactory.newLatLngZoom(bounds.getCenter(), 3));
    }

    @Override
    public void onMapLoaded() {
        if(mMap != null){
            displayHistoric();
        }
    }


    @Override
    public void onCameraChange(CameraPosition cameraPosition) {
        float maxZoom = 12.0f;
        if (cameraPosition.zoom > maxZoom){
            mMap.animateCamera(CameraUpdateFactory.zoomTo(maxZoom));
        }
    }
}
