import java.util.*


fun main()
{
    val sc = Scanner(System.`in`)
    val number = sc.next()
    var nums = Array(10) {0}
    for(i in 0 until number.length) nums[number[i]-'0']++
    var a = 0
    var b = 0
    for(i in 0 until 10)
    {
        if(i == 6 || i == 9) continue
        a = Math.max(a, nums[i])
    }

    b = nums[6]+nums[9]
    if(b % 2 != 0) b = b / 2 + 1
    else b /= 2
    print(Math.max(a,b))
}