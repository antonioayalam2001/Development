package com.company;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class EncryptTxt extends JFrame{
    String key = "AntonioMora";
    private JButton button1;
    private JPanel panel1;
    private JButton button2;
    private JTextArea textArea1;
    private JTextArea textArea2;

    public EncryptTxt() {
        super("Ejemplo");
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    JFileChooser fc = new JFileChooser();
                    fc.showOpenDialog(null);
                    String path = fc.getSelectedFile().getAbsolutePath();

                    File f = fc.getSelectedFile();
                    FileInputStream fis = new FileInputStream(f);
                    FileOutputStream fos = new FileOutputStream("encrypted.txt");
                    Thread.sleep(2000);

                    DESEncrypt.encrypt(key, fis, fos);

                } catch (Exception ex) {
                    System.out.print("Exception in EncryptTXT");
                }
            }
        });
        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {


                    JFileChooser fc = new JFileChooser();


                    fc.setCurrentDirectory(new File("./"));


                    fc.showOpenDialog(null);


                    String path = fc.getSelectedFile().getAbsolutePath();


                    File f = fc.getSelectedFile();


                    FileInputStream fis = new FileInputStream(f);


                    FileOutputStream fos = new FileOutputStream("decrypted.txt");


                    DESEncrypt.decrypt(key, fis, fos);


                    Thread.sleep(2000);




                } catch (Exception ex) {


                    System.out.print("Exception in EncryptTXT");


                }

            }
        });
    }

    public static void main(String[] args) {
        JFrame fr = new EncryptTxt();
        fr.setSize(600, 600);
        fr.setVisible(true);
    }
}
