fun main() {
    val n = readln()
    repeat(n.toInt()) {
        val x = readln()
        // % 3 then % 2
        if (x.toInt() < 3) println(x.toInt());
        else if ((x.toInt() % 3) % 2 == 0) println(0);
        else if (x.toInt() / 3 >= 3) println(0);
        else println(1);
    }
}