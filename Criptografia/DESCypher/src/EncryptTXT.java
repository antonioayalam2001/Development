import org.w3c.dom.ls.LSOutput;

import javax.crypto.SecretKey;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.security.NoSuchAlgorithmException;

public class EncryptTXT extends JFrame {
    String key = null;
    private JButton button1;
    private JButton button2;
    private JTextArea textField1;
    private JTextArea textField2;
    private JTextField clave;
    private JPanel panel1;
    private JButton generateKeyButton;

    public EncryptTXT() {
        super("Ejemplo");
        setContentPane(panel1);
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println(clave.getText());
                if (clave.getText().equals("")) {
                    JOptionPane.showMessageDialog(null, "La llave no puede ser vacia, por favor genera una");
                } else {
                    try {
                        key = clave.getText();
                        JFileChooser fc = new JFileChooser();
                        fc.setCurrentDirectory(new File("./"));
                        fc.showOpenDialog(null);
                        String path = fc.getSelectedFile().getAbsolutePath();

                        File f = fc.getSelectedFile();
                        FileReader fr = new FileReader(f);
                        BufferedReader br = new BufferedReader(fr);
                        String txt = "";
                        String line = "";
                        while (((line = br.readLine()) != null)) {
                            txt += line + "\n";
                        }
                        textField1.setText(txt);
                        FileInputStream fis = new FileInputStream(f);
                        FileOutputStream fos = new FileOutputStream("Marley_C.txt");
                        Thread.sleep(2000);

                        DESEncrypt.encrypt(key, fis, fos);

                    } catch (Exception ex) {
                        System.out.print("Exception in EncryptTXT");
                    }
                }
            }
        });
        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    key = clave.getText();
                    JFileChooser fc = new JFileChooser();
                    fc.setCurrentDirectory(new File("./"));
                    fc.showOpenDialog(null);
                    String path = fc.getSelectedFile().getAbsolutePath();
                    File f = fc.getSelectedFile();
                    FileInputStream fis = new FileInputStream(f);
                    FileOutputStream fos = new FileOutputStream("Marley_C_D.txt");
                    DESEncrypt.decrypt(key, fis, fos);
                    Thread.sleep(2000);
                    String decrypted = "";
                    InputStream decodedText = new FileInputStream("./Marley_C_D.txt");
                    int data;
                    while ((data = decodedText.read()) != -1) {
                        decrypted += (char) data;
                    }
                    textField2.setText(decrypted);
                } catch (Exception ex) {
                    System.out.print("Exception in EncryptTXT");
                }
            }
        });

        final SecretKey[] key = new SecretKey[1];
        final String[] claves = new String[1];
        generateKeyButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                DESEncrypt des = new DESEncrypt();
                try {
                    key[0] = des.clave();
                    claves[0] = des.convertSecretKeyToString(key[0]);
                    clave.setText(claves[0]);
                } catch (NoSuchAlgorithmException ex) {
                    ex.printStackTrace();
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        });
    }


    public static void main(String[] args) {
        JFrame fr = new EncryptTXT();
        fr.setSize(600, 600);
        fr.setVisible(true);
    }
}
