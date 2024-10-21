
interface MyCamera{
    void takeSnap();
    void recordVideo();
}
interface Mywifi{
    String[] getNetwork();
    void connectToNetwork(String network);
}
class MyCellPhone{
    void callNumber(int phoneNumber){
        System.out.println("Calling " + phoneNumber );
    }
    void pickCall(){
        System.out.println("Connecting...");
    }
}
class MySmartPhone extends MyCellPhone implements Mywifi,MyCamera{
    public void takeSnap(){
        System.out.println("Taking Snap");
    }
    public void recordVideo(){
        System.out.println("Recording video");
    }
    public String[] getNetwork(){
        System.out.println("Getting list of networks");
        String networks[]={"iphone","Airtel","JioFiber","Android"};
        return networks;
    }
    public void connectToNetwork(String network){
        System.out.println("Connected to the " + network+" successfully");
    }
}


public class Eighth {
    public static void main(String[] args) {
        MySmartPhone ms=new MySmartPhone();
        String[] res=ms.getNetwork();
        for (String r : res) {
            System.out.println(r);
        }
    }
    
}
