public class TimeSpan{
    long seconds;


    TimeSpan(long seconds){
        this.seconds=seconds;
        timeSet();
    }
    public  int days=0;
    public  int hours=0;
    public  int minutes=0;
    public  int second=0;

    private void timeSet(){
        days = (int) (seconds / 86400);
        seconds %= 86400;

        hours = (int) (seconds / 3600);
        seconds %= 3600;

        minutes = (int) (seconds / 60);
        second = (int) (seconds % 60);
    }
    void printTime(){
        System.out.println(days+" days: "+hours+" hours:"+minutes+" minutes:"+second+"seconds:");
    }



    public static void main(String args[]){
        TimeSpan ts=new TimeSpan(14400);
        ts.printTime();


    }

}

