/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package otherclock;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author jaime
 */
public class OtherClock {

    /**
     * @param args the command line arguments
     */
    public static final int INITIAL_COST_TIME = 36; //Initial time = 0 secs = cost 36

    public static void main(String[] args) throws IOException {

        int sec;

        System.out.println("Introduce tiempo en segundos:");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sec = Integer.parseInt(br.readLine());

        //Coste de transición:
        // 0 -> 0: 1
        // 0 -> 1: 0
        // 1 -> 2: 4
        // 2 -> 3: 1
        // 3 -> 4: 1
        // 4 -> 5: 2
        // 5 -> 0: 2
        // 6 -> 7: 1
        // 7 -> 8: 4
        // 8 -> 9: 0
        // 9 -> 0: 2 
	// 6 -> 0: 1 -- Caso de 60seg o 60min
        
        int cost_transition[] = {0, 0, 4, 1, 1, 2, 2, 1, 4, 0, 2, 1};
        int time[] = {0, 0, 0, 0, 0, 0};
        int cost = INITIAL_COST_TIME;

        for (int i = 1; i <= sec; i++) {
           
            time[0] += 1;
            
            for (int j = 0; j < time.length; j++) {
                
                cost += cost_transition[((j % 2) != 0 && j == 6)?time[cost_transition.length-1]:time[j]];
                
                
                if ((time[j] == 10 && (j % 2) == 0) || (time[j] == 6 && (j % 2) != 0)) {
                    time[j] = 0;
                    
                    if (j < time.length) {
                        time[j + 1] += 1;
                    }
                }

            }

        }
        for (int i = 0; i < time.length; i++) {
            System.out.print(time[i] + " - ");
        }
        System.out.println("");
        System.out.println("Cost: " + cost);

    }

}

