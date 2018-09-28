package bzh.buno.nativeapp

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        simpleText.text = stringFromJNI()

        // Example of a call with string param and returned value
        complexText.text = stringFromCplus("qhgqfmghamqgaqbqhlbtartahrtqgeabmi")

        // Example of a call with returned array value
        val array = arrayFromCplus()
        val stringBuilder = StringBuilder()
        for (i in 0 until array.size) {
            stringBuilder.append(array[i])
            stringBuilder.append("\n")
        }
        multilineText.text = stringBuilder.toString()
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    external fun stringFromCplus(msg: String): String

    external fun arrayFromCplus(): Array<String>

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
