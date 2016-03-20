/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tlang;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author jaime
 */
public class TLang {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {

        String line;
        int first_number, second_number, result;

        while (true) {

            first_number = second_number = result = 0;

            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            line = br.readLine();
            if (correct_sintactics_tlang(line)) {

                line = line.substring(line.indexOf('^') + 1, line.length());

                char type_operation = line.charAt(0); //Get type of operation =, @, #

                //Get first and second number of the line
                first_number = Integer.parseInt(line.substring(line.indexOf(' ') + 1, line.indexOf(' ', line.indexOf(' ') + 1)));
                second_number = Integer.parseInt(line.substring(line.lastIndexOf(' ') + 1, line.length() - 1));

                result = do_operation(type_operation, first_number, second_number);
                System.out.println("Result: " + result);

            } else {
                System.err.println("Incorrect Sintactics of the line.");
            }

        }

    }

    //If my String have the correct sintactis (^ ... $)
    public static boolean correct_sintactics_tlang(String line) {
        return line.indexOf('^') > -1 && line.indexOf('$') > -1 && line.indexOf('^') < line.indexOf('$');
    }

    public static int do_operation(char type_operation, int fn, int sn) {
        int result = 0;
        switch (type_operation) {

            case '=':
                result = fn + sn;
                break;
            case '#':
                result = fn * sn;
                break;
            case '@':
                result = fn - sn;
                break;
        }
        return result;

    }

}
