import kotlin.math.max

fun main() {
    val n: Int = readln().toInt()

    repeat(n) {
        val t = readln().split(" ").map { it.toInt() }
        val x: Int = t[0]
        val y: Int = t[1]
        println(max((2 - ((y / x) % 3)) * x - (y % x), 0))
    }
}