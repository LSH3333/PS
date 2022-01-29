import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Array;
import java.util.*;

class Node
{
    char root;
    char left;
    char right;
    Node(char _root, char _left, char _right)
    { root = _root; left = _left; right = _right;}
}

public class Main
{
    static ArrayList<Character> pre = new ArrayList<>();
    static ArrayList<Character> in = new ArrayList<>();
    static ArrayList<Character> post = new ArrayList<>();
    static Map<Character, Node> map = new HashMap<Character, Node>();

    static void PreOrder(char root)
    {
        if(root == '.') return;
        pre.add(root);
        PreOrder(map.get(root).left);
        PreOrder(map.get(root).right);
    }

    static void PostOrder(char root)
    {
        if(root == '.') return;
        PostOrder(map.get(root).left);
        PostOrder(map.get(root).right);
        post.add(root);
    }

    static void InOrder(char root)
    {
        if(root == '.') return;
        InOrder(map.get(root).left);
        in.add(root);
        InOrder(map.get(root).right);
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] _s;
        for(int i = 0; i < n; i++)
        {
            _s = br.readLine().split(" ");
            map.put(_s[0].charAt(0), new Node(_s[0].charAt(0), _s[1].charAt(0), _s[2].charAt(0)));
        }

        PreOrder('A');
        PostOrder('A');
        InOrder('A');

        for(Character x : pre) System.out.print(x);
        System.out.println();
        for(Character x : in) System.out.print(x);
        System.out.println();
        for(Character x : post) System.out.print(x);
    }

}
