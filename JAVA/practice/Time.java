public class Time {
    private int days;
    private int hours;
    private int minutes;
    private int seconds;
    public Time(int totalSeconds){
        convertSeconds(totalSeconds);
    }
    private void convertSeconds(int totalSeconds){
        days=totalSeconds/84000;
        totalSeconds%=84000;

        hours=totalSeconds/3600;
        totalSeconds%=3600;

        minutes=totalSeconds/60;
        totalSeconds%=60;

        seconds=totalSeconds;
    }
    void displayTime(){
        System.out.println("days: "+days +"hours: "+hours +"minutes: "+minutes+"seconds: "+seconds);
    }

    public static void main(String[] args) {
        int totalSeconds=1141381486;
        Time convert=new Time(totalSeconds);
        convert.displayTime();        
    }
}
