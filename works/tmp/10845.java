import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;

class Queue
{
    int MAX = 10100;
    int[] arr;
    int f;
    int b;

    public Queue()
    {
        arr = new int[MAX];
        f = 0;
        b = 0;
    }

    private int nextPos(int i)
    {
        if(i+1 == MAX) return 0;
        else return i+1;
    }

    void push(int x)
    {
        b = nextPos(b);
        arr[b] = x;
    }

    int pop()
    {
        if(b == f) return -1;
        f = nextPos(f);
        return arr[f];
    }

    int size()
    {
        if(f == b) return 0;
        else if(f < b) return b - f;
        else return (MAX-f-1) + (b-1);
    }

    int empty()
    {
        if(b == f) return 1;
        else return 0;
    }

    int front()
    {
        if(f == b) return -1;
        return arr[nextPos(f)];
    }

    int back()
    {
        if(f == b) return -1;
        return arr[b];
    }
}

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Queue queue = new Queue();
        int N = Integer.parseInt(br.readLine());
        while(N-- > 0)
        {
            String[] _s = br.readLine().split(" ");
            String op = _s[0];
            if(Objects.equals(op, "push"))
            {
                int x = Integer.parseInt(_s[1]);
                queue.push(x);
            }
            else if(Objects.equals(op, "pop"))
            {
                sb.append(queue.pop()).append('\n');
            }
            else if(Objects.equals(op, "size"))
            {
                sb.append(queue.size()).append('\n');
            }
            else if(Objects.equals(op, "empty"))
            {
                sb.append(queue.empty()).append('\n');
            }
            else if(Objects.equals(op, "front"))
            {
                sb.append(queue.front()).append('\n');
            }
            else if(Objects.equals(op, "back"))
            {
                sb.append(queue.back()).append('\n');
            }
        }
        System.out.print(sb);
    }
}
