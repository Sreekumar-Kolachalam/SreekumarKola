import java.util.Scanner;

class Arm
{
    int a;
    
    public Arm(int a)
    {
        this.a = a;
    }
    
    boolean isArmNum()
    {  
        int temp = a;
        int sum = 0;
        while(temp > 0)
        {
            int b = temp % 10;
            sum += b*b*b;
            temp /= 10;
        }
        return sum == a;
    }
}

public class armstrong
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number:");
        int n = sc.nextInt();
        
        Arm a1 = new Arm(n);
        if(a1.isArmNum())
            System.out.println("It is an Armstrong number");
        else
            System.out.println("It is not an Armstrong number");
    }
}

