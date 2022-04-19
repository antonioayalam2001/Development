package com.company;

import java.util.*;
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println(" Input the plaintext message : ");
        String plaintext = "Could you be loved and be loved?\n" +
                "Could you be loved and be loved?\n" +
                "Don't let them fool ya\n" +
                "Or even try to school ya, oh, no\n" +
                "We've got a mind of our own\n" +
                "So go to Hell if what you're thinking is not right\n" +
                "Love would never leave us alone\n" +
                "A-in the darkness ya must come out to light\n" +
                "Could you be loved and be loved?\n" +
                "Could you be loved, whoa now, and be loved?\n" +
                "The road of life is rocky and you may stumble too\n" +
                "So while you point your fingers someone else is judging you\n" +
                "Love your brotherman\n" +
                "Could you be, could you be, could you be loved?\n" +
                "Could you be, could you be loved?\n" +
                "Could you be, could you be, could you be loved?\n" +
                "Could you be, could you be loved?\n" +
                "Don't let them change ya, oh\n" +
                "Or even rearrange ya, oh, no\n" +
                "We've got a life to live\n" +
                "They say, only, only\n" +
                "Only the fittest of the fittest shall survive\n" +
                "Stay alive, ay\n" +
                "Could you be loved and be loved?\n" +
                "Could you be loved, whoa now, and be loved?\n" +
                "Never gonna miss your water until your well runs dry\n" +
                "No matter how you treat him, man will never be satisfied\n" +
                "Say something (could you be, could you be, could you be loved?)\n" +
                "(Could you be, could you be loved?) Say something\n" +
                "Say something (could you be, could you be, could you be loved?)\n" +
                "Say something (could you be, could you be loved?)";
        System.out.println(" Enter the value by which each character in the plaintext message gets shifted : ");
        int shift = sc.nextInt();
        String ciphertext = "";
        char alphabet;
        for(int i=0; i < plaintext.length();i++)
        {
            // Shift one character at a time
            alphabet = plaintext.charAt(i);

            // if alphabet lies between a and z
            if(alphabet >= 'a' && alphabet <= 'z')
            {
                // shift alphabet
                alphabet = (char) (alphabet + shift);
                // if shift alphabet greater than 'z'
                if(alphabet > 'z') {
                    // reshift to starting position
                    alphabet = (char) (alphabet+'a'-'z'-1);
                }
                ciphertext = ciphertext + alphabet;
            }

            // if alphabet lies between 'A'and 'Z'
            else if(alphabet >= 'A' && alphabet <= 'Z') {
                // shift alphabet
                alphabet = (char) (alphabet + shift);

                // if shift alphabet greater than 'Z'
                if(alphabet > 'Z') {
                    //reshift to starting position
                    alphabet = (char) (alphabet+'A'-'Z'-1);
                }
                ciphertext = ciphertext + alphabet;
            }
            else {
                ciphertext = ciphertext + alphabet;
            }

        }
        System.out.println(" ciphertext : " + ciphertext);
    }
}