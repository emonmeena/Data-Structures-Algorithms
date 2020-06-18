package SingletonClass;

public class AppConfig {
    private AppConfig(){}
//    static  AppConfig obj = new AppConfig();
static AppConfig obj = null;
    public static  AppConfig getInstance(){
        if(obj == null){obj = new AppConfig();}
        return obj;
    }
}