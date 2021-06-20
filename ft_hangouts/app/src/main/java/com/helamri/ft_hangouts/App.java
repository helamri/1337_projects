package com.helamri.ft_hangouts;

import android.app.Activity;
import android.app.Application;
import android.os.Bundle;
import android.widget.Toast;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class App extends Application implements Application.ActivityLifecycleCallbacks {
    String timer;
    @Override
    public void onCreate() {
        super.onCreate();
        registerActivityLifecycleCallbacks(this);
    }

    private int activityReferences = 0;
    private boolean isActivityChangingConfigurations = false;

    @Override
    public void onActivityCreated(Activity activity, Bundle bundle) {

    }
    Date currentTime;
    @Override
    public void onActivityStarted(Activity activity) {
        if (++activityReferences == 1 && !isActivityChangingConfigurations) {
            DateFormat df = new SimpleDateFormat("HH:mm:ss");
            if(timer != null){
                Toast.makeText(getApplicationContext(), "Lat visit: "+timer,
                    Toast.LENGTH_SHORT).show();}
        }
    }

    @Override
    public void onActivityResumed(Activity activity) {

    }

    @Override
    public void onActivityPaused(Activity activity) {

    }

    @Override

    public void onActivityStopped(Activity activity) {

        isActivityChangingConfigurations = activity.isChangingConfigurations();
        if (--activityReferences == 0 && !isActivityChangingConfigurations) {
            DateFormat df = new SimpleDateFormat("HH:mm:ss");
            currentTime = Calendar.getInstance().getTime();
            timer = df.format(currentTime);
        }
    }

    @Override
    public void onActivitySaveInstanceState(Activity activity, Bundle bundle) {

    }

    @Override
    public void onActivityDestroyed(Activity activity) {

    }
}