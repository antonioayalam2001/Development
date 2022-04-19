import javax.crypto.Cipher;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.io.FileInputStream;
import java.nio.charset.StandardCharsets;
import java.util.Base64;
import java.util.Scanner;
import java.util.UUID;

public class Cypher {
        private final static String algorythm = "DES";
        private final static String modeCBC = "DES/CBC/PKCS5Padding";
        private final static String modeECB = "DES/ECB/NoPadding";
        private final static String modeCFB = "DES/CFB/NoPadding";
        private final static String modeOFB = "AES/OFB/NoPadding";



    public String StringEncrypt(String key, String vectorInitial, String in) throws Exception {
        Cipher cipher = Cipher.getInstance(modeCFB);
//        It can be used to construct a SecretKey from a byte array, without having to go through a (provider-based) SecretKeyFactory.
        SecretKeySpec keySpec = new SecretKeySpec(key.getBytes(),algorythm);
//     Forma de declarar el vector de inicialización;
        IvParameterSpec vector = new IvParameterSpec(vectorInitial.getBytes());
        cipher.init(Cipher.ENCRYPT_MODE,keySpec,vector);
        byte[] textEncrypted = cipher.doFinal(in.getBytes());
        return (Base64.getEncoder().encodeToString(textEncrypted));
    }

    public static String generateSecreKey() {
        String uuid = UUID.randomUUID().toString();
        uuid = uuid.replaceAll("-", "");
        return uuid.substring(0, 8);
    }
    public String StringDecrypth (String key, String vectoriInitial, String enc) throws Exception{
        Cipher cipher = Cipher.getInstance(modeCFB);
        SecretKeySpec keySpec= new SecretKeySpec(key.getBytes(),algorythm);
        IvParameterSpec vector = new IvParameterSpec(vectoriInitial.getBytes());
        byte [] en = Base64.getDecoder().decode(enc);
//        cipher.init(Cipher.DECRYPT_MODE,keySpec,vector);
        cipher.init(Cipher.DECRYPT_MODE,keySpec);

        byte[] textDecrypted = cipher.doFinal(en);
        return new String (textDecrypted);
    }


    public static void main(String[] args) throws Exception {
        String key = generateSecreKey();
//        String key = "92AE31A79FEEB2A3"; //llave
        Cypher cy= new Cypher();
        String iv = "01234567"; // vector de inicialización
//        FileInputStream file = new FileInputStream("Imagen1.jpeg");
//        byte[] buffer = new byte[1024];
//        int read;
//        while ((read = file.read(buffer))!=-1){
//
//        }


            String cleartext = "hola";
            System.out.println("Texto encriptado: "+ cy.StringEncrypt(key,iv,cleartext));
            System.out.println("Texto desencriptado: "+ cy.StringDecrypth(key,iv, cy.StringEncrypt(key,iv,cleartext)));
//        System.out.println("El texto cifrado resulta en " + cy.StringDecrypth(key,iv,cy.}));

    }

}


