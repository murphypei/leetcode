import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        String[] dates = new String[n];
        String[] times = new String[n];
        int[] use = new int[n];
        for(int i = 0; i<n ;i++){
            dates[i] = input.next();
            times[i] = input.next();
            use[i] = input.nextInt();
        }
        int m = input.nextInt();
        String[] startDate = new String[m];
        String[] startTime = new String[m];
        String[] endDate = new String[m];
        String[] endTime = new String[m];
        for(int i = 0; i<m; i++){
            startDate[i] = input.next();
            startTime[i] = input.next();
            endDate[i] = input.next();
            endTime[i] = input.next();
        }
        for(int i = 0; i<m; i++){
            int result = 0;
            for(int j = 0; j<n; j++){
                if(within(startDate[i]+" "+startTime[i],endDate[i]+" "+endTime[i],dates[j]+" "+ times[j])) result+=use[j];
            }
            System.out.println(result);
        }
    }
    private static boolean within(String date1,String date2,String date3){
        DateFormat df = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");
        try {
            Date dt1 = df.parse(date1);
            Date dt2 = df.parse(date2);
            Date dt3 = df.parse(date3);
            if (dt1.getTime() <= dt3.getTime() && dt2.getTime() >= dt3.getTime()) {
                return true;
            } else {
                return false;
            }
        }catch (ParseException e){
            return false;
        }
    }
}