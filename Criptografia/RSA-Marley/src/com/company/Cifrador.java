package com.company;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.Scanner;

public class Cifrador extends JFrame {
    private JPanel panel1;
    private JButton archivoButton;
    private JButton button2;
    private JButton button3;
    private JLabel titulo1;
    private JTextArea archivoNormal;
    private JTextArea archivoCifrado;

    public Cifrador() {
        super("Ejemplo");
        setContentPane(panel1);

//        Getting the file from the user
        archivoButton.addActionListener(new ActionListener() {
            @Override
    public void actionPerformed(ActionEvent e) {
        JFileChooser fc = new JFileChooser();
        fc.showOpenDialog(null);
        File archive = fc.getSelectedFile();
                Scanner sc = new Scanner(System.in);

                try {
                    FileReader fr = new FileReader(archive);
                    BufferedReader br = new BufferedReader(fr);
                    String txt = "";
                    String line = "";
                    while(((line=br.readLine()))!=null){
                        txt+=line+"\n";
                    }
                    archivoNormal.setText(txt);
                    JOptionPane.showMessageDialog(null,"Leido de forma correcta de forma correcta");
                    System.out.println(" Enter the value by which each character in the plaintext message gets shifted : ");
                    int shift = sc.nextInt();
                    String ciphertext = "";
                    char alphabet;
                    for(int i=0; i < txt.length();i++)
                    {
                        // Shift one character at a time
                        alphabet = txt.charAt(i);

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
                    archivoCifrado.setText(ciphertext);
                } catch (FileNotFoundException ex) {
                    ex.printStackTrace();
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
});
}
    public static void main(String[] args) {
        JFrame fr = new Cifrador();
        fr.setSize(600, 600);
        fr.setVisible(true);
    }
}



