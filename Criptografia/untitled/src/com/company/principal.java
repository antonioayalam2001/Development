package com.company;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.io.File;
import java.io.FileOutputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class principal {
    //Función para obtener selección de usuario en el menu
    public static int getData() {
        Scanner entradaDeDatos = new Scanner(System.in);
        int seleccionUsuario = 0;
        seleccionUsuario = entradaDeDatos.nextInt();
        return seleccionUsuario;
    }

    public static void main(String[] args) throws BadPaddingException {
        // Programa principal, cifra y descifra el contenido de un fichero utilizando una clave.

        int seleccionUsuario = 0;
        Scanner entradaDeDatos = new Scanner(System.in);
        String nombreArchivo = "";
        String rutaPrincipal = "./";
        Path rutaFinal;
        String contenidoFichero = "";
        String contenidoCifrado = "";
        File fichero;
        Cipher desCipher;
        byte[] lectura;
        byte[] mensajeCifrado;
        byte[] mensajeDescifrado;

        //Genero la key para el cifrado DES
        KeyGenerator keygen = null;
        try {
            keygen = KeyGenerator.getInstance("DES/ECB/PKCS5Padding");
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        SecretKey key = keygen.generateKey();

        do {
            System.out.println("***Programa de cifrado***");
            System.out.println("Selecciona una opción:");
            System.out.println("    1.Cifrar");
            System.out.println("    2.Descifrar");
            System.out.println("    3.Salir");

            System.out.print("Opcion: ");
            try {
                seleccionUsuario = getData();
            } catch (Exception e) {
            }

            switch (seleccionUsuario) {
                case 1:
                    // Obtener nombre de fichero para cifrar
                    System.out.print("Introduce el nombre del fichero para cifrar: ");
                    nombreArchivo = entradaDeDatos.next();
                    rutaFinal = Paths.get(rutaPrincipal + nombreArchivo);
                    fichero = new File(rutaPrincipal + nombreArchivo);

                    if (!fichero.exists()) {
                        System.out.println("El fichero no existe, volviendo al menu principal");
                        continue;
                    } else if (!fichero.canRead()) {
                        System.out.println("No se puede leer el fichero, volviendo al menu principal");
                    } else {
                        try {
                            // Leer el archivo y guardar sus datos en una cadena
                            lectura = Files.readAllBytes(rutaFinal); //Leer el contenido del fichero
                            System.out.println("El contenido del fichero para cifrar es: " + new String(lectura));

                            //Introducir la key en el cifrador
                            desCipher = Cipher.getInstance("DES");
                            desCipher.init(Cipher.ENCRYPT_MODE, key);

                            //Cifrar el contenido del fichero
                            mensajeCifrado = desCipher.doFinal(lectura);
                            System.out.println("El mensaje cifrado es: " + new String(mensajeCifrado));

                            // Guardar el contenido del fichero cifrado en un nuevo fichero
                            fichero = new File(rutaPrincipal + "CIFRADO_" + nombreArchivo);
                            FileOutputStream fos = new FileOutputStream(fichero, false);
                            fos.write(mensajeCifrado);
                            fos.close();
                            System.out.println("Fichero cifrado creado: " + rutaPrincipal + "CIFRADO_" + nombreArchivo);

                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                    break;
                case 2:
                    // Obtener nombre de fichero para cifrar
                    System.out.print("Introduce el nombre del fichero para descifrar: ");
                    nombreArchivo = entradaDeDatos.next();
                    rutaFinal = Paths.get(rutaPrincipal + nombreArchivo);
                    fichero = new File(rutaPrincipal + nombreArchivo);

                    if (!fichero.exists()) {
                        System.out.println("El fichero no existe, volviendo al menu principal");
                        continue;
                    } else if (!fichero.canRead()) {
                        System.out.println("No se puede leer el fichero, volviendo al menu principal");
                    } else {
                        try {
                            // Leer el archivo y guardar sus datos en una cadena
                            lectura = Files.readAllBytes(rutaFinal); //Leer el contenido del fichero
                            System.out.println("El contenido del fichero cifrado es: " + new String(lectura));

                            //Introducir la key en el cifrador
                            desCipher = Cipher.getInstance("DES");
                            desCipher.init(Cipher.DECRYPT_MODE, key);

                            //Cifrar el contenido del fichero
                            mensajeDescifrado = desCipher.doFinal(lectura);
                            System.out.println("El mensaje original era: " + new String(mensajeDescifrado));

                            // Guardar el contenido del fichero cifrado en un nuevo fichero
                            fichero = new File(rutaPrincipal + "DESCIFRADO_" + nombreArchivo.substring(nombreArchivo.indexOf("_")));
                            FileOutputStream fos = new FileOutputStream(fichero, false);
                            fos.write(mensajeDescifrado);
                            fos.close();
                            System.out.println("Fichero cifrado creado: " + rutaPrincipal + "DESCIFRADO_" + nombreArchivo.substring(nombreArchivo.indexOf("_")));

                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                    break;
                case 3:
                    System.out.println("Fin del programa");
                    break;
                default:
                    System.out.println("Introduzca un valor válido");
                    break;
            }
        } while (seleccionUsuario != 3);

    }
}