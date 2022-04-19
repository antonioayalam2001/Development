import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.security.NoSuchAlgorithmException;
import java.util.Base64;

public class DESEncrypt {
    SecretKey originalKey;

    public static void encrypt(String key, InputStream is, OutputStream os) throws Exception {
        encryptOrDecrypt(key, Cipher.ENCRYPT_MODE, is, os);
    }

    public static void decrypt(String key, InputStream is, OutputStream os) throws Exception {
        encryptOrDecrypt(key, Cipher.DECRYPT_MODE, is, os);
    }

    public static void encryptOrDecrypt(String key, int mode, InputStream is, OutputStream os) throws Exception {

        DESEncrypt encrypt = new DESEncrypt();
        SecretKeyFactory skf = SecretKeyFactory.getInstance("DES");
        SecretKey desKey = encrypt.convertString(key);
        String clave = encrypt.convertSecretKeyToString(desKey);
        Cipher cipher = Cipher.getInstance("DES");
        if (mode == Cipher.ENCRYPT_MODE) {
            cipher.init(Cipher.ENCRYPT_MODE, desKey);
            CipherInputStream cis = new CipherInputStream(is, cipher);
            encrypt.makeFile(cis, os);
        } else if (mode == Cipher.DECRYPT_MODE) {
            cipher.init(Cipher.DECRYPT_MODE, desKey);
            CipherOutputStream cos = new CipherOutputStream(os, cipher);
            encrypt.makeFile(is, cos);
        }
    }

    public SecretKey clave() throws Exception {
        KeyGenerator generadorDES = KeyGenerator.getInstance("DES");
        generadorDES.init(56);
        SecretKey clave = generadorDES.generateKey();
        return clave;
    }

    public SecretKey convertString(String key) {
        try {
            byte[] decodedKey = Base64.getDecoder().decode(key);
            originalKey = new SecretKeySpec(decodedKey, 0, decodedKey.length, "DES");
            System.out.println(originalKey);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return originalKey;
    }

    public String convertSecretKeyToString(SecretKey claveBits) throws NoSuchAlgorithmException {
        byte[] rawData = claveBits.getEncoded();
        String encodedKey = Base64.getEncoder().encodeToString(rawData);
        return encodedKey;
    }

    public void makeFile(InputStream is, OutputStream os) throws IOException, IOException {
        byte[] bytes = new byte[64];
        int numBytes;
        while ((numBytes = is.read(bytes)) != -1) {
            os.write(bytes, 0, numBytes);
        }
        os.flush();
        os.close();
        is.close();
    }
}
