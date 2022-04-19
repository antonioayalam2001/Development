import javax.crypto.Cipher;
import javax.crypto.CipherOutputStream;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Base64;
import java.util.UUID;

public class DESCypher {
    private final static String algorythm = "DES";
//    Mode We must use
//    This one works
    private final static String modeCBC = "DES/CBC/NoPadding";
//    Haven't tried
    private final static String modeECB = "DES/ECB/NoPadding";
//    This one works
    private final static String modeCFB = "DES/CFB/NoPadding";
    private final static String modeOFB = "DES/OFB/NoPadding";



    public String StringEncrypt(String key, String vectorInitial, String in) throws Exception {
        Cipher cipher = Cipher.getInstance(modeOFB);
//        It can be used to construct a SecretKey from a byte array, without having to go through a (provider-based) SecretKeyFactory.
        SecretKeySpec keySpec = new SecretKeySpec(key.getBytes(),algorythm);
        FileInputStream file = new FileInputStream("src/Image1.jpeg");
        FileOutputStream outStream = new FileOutputStream("Encrypted.jpeg");

//     Forma de declarar el vector de inicialización;
        IvParameterSpec vector = new IvParameterSpec(vectorInitial.getBytes());
        cipher.init(Cipher.ENCRYPT_MODE,keySpec,vector);
//        cipher.init(Cipher.ENCRYPT_MODE,keySpec);
        CipherOutputStream cos = new CipherOutputStream(outStream,cipher);
        byte[] textEncrypted = new byte[1024];
        int read;
        while((read= file.read(textEncrypted))!=-1){
            cos.write(textEncrypted,0,read);
        }
        return (Base64.getEncoder().encodeToString(textEncrypted));
    }

    public static String generateSecreKey() {
//        UUID allows us to getan Universal Unique IDentifier
//        36 characters (128-bits)
        String uuid = UUID.randomUUID().toString();
//        2b733549-d2cc-40f0-b7f3-9bfa9f3c1b89 Result that we get from the convert function to retrive a tring
                uuid = uuid.replaceAll("-", "");
//        Only getting 8 cause that is what our algorithm needs
        return uuid.substring(0, 8);
    }

    public String StringDecrypth (String key, String vectoriInitial, String enc) throws Exception{
//        Setting up the cipher
        Cipher cipher = Cipher.getInstance(modeOFB);
//        Spect to the key
        SecretKeySpec keySpec= new SecretKeySpec(key.getBytes(),algorythm);
//        Vector
        IvParameterSpec vector = new IvParameterSpec(vectoriInitial.getBytes());
//        Oppening the file
        FileInputStream file = new FileInputStream("Encrypted.jpeg");
//        File were we're gonna write all the information
        FileOutputStream outStream = new FileOutputStream("Decrypted.jpeg");
//      Decrypting
        cipher.init(Cipher.DECRYPT_MODE,keySpec,vector);
//        cipher.init(Cipher.DECRYPT_MODE,keySpec);
        CipherOutputStream cos = new CipherOutputStream(outStream,cipher);
        byte[] textEncrypted = file.read(1024,4,);
        int read;
        while((read= file.read(textEncrypted))!=-1){
            cos.write(textEncrypted,0,read);
        }

        byte[] textDecrypted = cipher.doFinal(textEncrypted);
        return new String (textDecrypted);
    }


    public static void main(String[] args) throws Exception {
        String key = generateSecreKey();
//        String key = "92AE31A79FEEB2A3"; //llave
        DESCypher cy= new DESCypher();
        String iv = "01234567"; // vector de inicialización

        String cleartext = "Que onda cerca";
        System.out.println("Texto encriptado: "+ cy.StringEncrypt(key,iv,cleartext));
        System.out.println("Texto desencriptado: "+ cy.StringDecrypth(key,iv, cy.StringEncrypt(key,iv,cleartext)));
    }
}
