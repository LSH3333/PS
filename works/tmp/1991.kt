import java.io.BufferedReader
import java.io.InputStreamReader

var pre = ArrayList<Char>()
var inorder = ArrayList<Char>()
var post = ArrayList<Char>()
var map = mutableMapOf<Char, Node>()

class Node(_root:Char, _left:Char, _right:Char)
{
    var root = _root
    var left = _left
    var right = _right
}

fun PreOrder(root:Char)
{
    if(root == '.') return
    pre.add(root)
    val node = map[root]
    if(node != null) PreOrder(node.left)
    if(node != null) PreOrder(node.right)
}

fun PostOrder(root:Char)
{
    if(root == '.') return
    val node = map[root]
    if(node != null) PostOrder(node.left)
    if(node != null) PostOrder(node.right)
    post.add(root)
}

fun InOrder(root:Char)
{
    if(root == '.') return
    val node = map[root]
    if(node != null) InOrder(node.left)
    inorder.add(root)
    if(node != null) InOrder(node.right)
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var n = Integer.parseInt(br.readLine())
    for(i in 0 until n)
    {
        var _s = br.readLine().split(' ')
        map.put(_s[0][0], Node(_s[0][0], _s[1][0], _s[2][0]))
    }

    PreOrder('A')
    PostOrder('A')
    InOrder('A')

    for(x in pre) print(x)
    println()
    for(x in inorder) print(x)
    println()
    for(x in post) print(x)
}