public class TimeSpan {
    private int hours;
    private int minutes;
    private int seconds;
    
    public TimeSpan(int hours,int minutes,int seconds){
        this.minutes=minutes;
        this.hours=hours;
        this.seconds=seconds;
    }
    private void normalize(){
    if(seconds>=60){
        minutes+=seconds/60;
        seconds%=60;
    }        
    else if (seconds < 0) {
        minutes -= (Math.abs(seconds) / 60) + 1;
        seconds = 60 - Math.abs(seconds) % 60;
    }
    if(minutes>=60){
        hours+=minutes/60;
        minutes%=60;
    }
    else if (minutes < 0) {
        hours -= (Math.abs(minutes) / 60) + 1;
        minutes = 60 - Math.abs(minutes) % 60;
    }
    if(hours<0){
        hours=0;
        minutes=0;
        seconds=0;
    }
    }
    public void add(TimeSpan other){
        this.hours+=other.hours;
        this.seconds+=other.seconds;
        this.minutes+=other.minutes;
        normalize();
    }
    public void subtract(TimeSpan other){
        this.hours-=other.hours;
        this.seconds-=other.seconds;
        this.minutes-=other.minutes;
        normalize();
    }

    public String toString(){
        return String.format("%02d:%02d:%02d", hours, minutes, seconds);
    }

    public static void main(String[] args) {
        TimeSpan time1 = new TimeSpan(1, 70, 80); // Normalizes to 02:11:20
        TimeSpan time2 = new TimeSpan(0, 50, 40); // 00:50:40

        System.out.println("Time 1: " + time1); // Output: Time 1: 02:11:20
        System.out.println("Time 2: " + time2); // Output: Time 2: 00:50:40

        time1.add(time2);
        System.out.println("After Adding: " + time1); // Output: After Adding: 03:02:00

        time1.subtract(new TimeSpan(1, 30, 0));
        System.out.println("After Subtracting: " + time1);
    }

}
