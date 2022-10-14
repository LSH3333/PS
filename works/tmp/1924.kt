import java.util.*


fun main()
{
    val sc = Scanner(System.`in`)
    var v = ArrayList<ArrayList<Int>>()
    for(i in 1 .. 12)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
        {
            var al = ArrayList<Int>()
            for(j in 0 until 31) al.add(0)
            v.add(al)
        }
        else if(i==4 || i==6 || i ==9 || i==11)
        {
            var al = ArrayList<Int>()
            for(j in 0 until 30) al.add(0)
            v.add(al)
        }
        else
        {
            var al = ArrayList<Int>()
            for(j in 0 until 28) al.add(0)
            v.add(al)
        }
    }

    var n = 0
    for(i in 0 until v.size)
    {
        for(j in 0 until v[i].size)
        {
            v[i][j] = n
            n = (n + 1) % 7
        }
    }

    var x = sc.nextInt(); var y = sc.nextInt()
    val day = arrayOf("MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN")
    print(day[v[x-1][y-1]])
}