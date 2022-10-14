import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int N = sc.nextInt();
        int w = 4 * N - 3;
        int h = 2 * N - 1;
        int mid = w-N*2; // 가운데 공백
        ArrayList<ArrayList<Character>> board = new ArrayList<ArrayList<Character>>();

        // 첫 줄
        ArrayList<Character> a = new ArrayList<>();
        for(int i = 0; i < N; i++) a.add('*');
        for(int i = 0; i < mid; i++) a.add(' ');
        for(int i = 0; i < N; i++) a.add('*');
        board.add(a);
        mid-=2;

        int l=0;
        for(int i = 1; i < N; i++)
        {
            a = new ArrayList<>();
            for(int j = 0; j < i; j++) a.add(' ');
            a.add('*');
            for(int j = 0; j < N-2; j++) a.add(' ');
            a.add('*');
            for(int j = 0; j < mid; j++) a.add(' ');
            if(mid > 0) a.add('*');
            mid-=2;
            for(int j = 0; j < N-2; j++) a.add(' ');
            a.add('*');
            l = i-1;
            board.add(a);
        }
        mid = 1;

        for(int i = N; i < h-1; i++)
        {
            a = new ArrayList<>();
            for(int j = 0; j < l; j++) a.add(' ');
            l--;
            a.add('*');
            for(int j = 0; j < N-2; j++) a.add(' ');
            a.add('*');
            for(int j = 0; j < mid; j++) a.add(' ');
            mid += 2;
            a.add('*');
            for(int j = 0; j <N-2; j++) a.add(' ');
            a.add('*');
            board.add(a);
        }

        a = new ArrayList<>();
        for(int i = 0; i < N; i++) a.add('*');
        for(int i = 0; i < mid; i++) a.add(' ');
        for(int i = 0; i <N; i++) a.add('*');
        board.add(a);

        for(int i = 0; i < h; i++)
        {
            for(Character x : board.get(i)) System.out.print(x);
            System.out.println();
        }
    }
}
