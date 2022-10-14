import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;

class Stack
{
    int[] arr;
    int ptr;

    public Stack()
    {
        arr = new int[10001];
        ptr = -1;
    }

    void push(int x)
    {
        arr[++ptr] = x;
    }

    int pop()
    {
        if(ptr == -1) return -1;
        return arr[ptr--];
    }

    int size()
    {
        return ptr+1;
    }

    int empty()
    {
        if(ptr == -1) return 1;
        else return 0;
    }

    int top()
    {
        if(ptr == -1) return -1;
        return arr[ptr];
    }


}

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Stack stack = new Stack();
        int N = Integer.parseInt(br.readLine());
        while(N-- > 0)
        {
            String[] _s = br.readLine().split(" ");
            String op = _s[0];
            if(Objects.equals(op, "push"))
            {
                int x = Integer.parseInt(_s[1]);
                stack.push(x);
            }
            else if(Objects.equals(op, "pop"))
            {
                sb.append(stack.pop()).append("\n");
            }
            else if(Objects.equals(op, "size"))
            {
                sb.append(stack.size()).append("\n");
            }
            else if(Objects.equals(op, "empty"))
            {
                sb.append(stack.empty()).append("\n");
            }
            else if(Objects.equals(op, "top"))
            {
                sb.append(stack.top()).append("\n");
            }
        }
        System.out.print(sb);
    }
}
