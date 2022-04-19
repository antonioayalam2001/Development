/**********************************************
*                                             *
*   Metodo de la GUI                          *
*   Integrantes                               *
*       Mora Ayala Jose Antonio               *
*       Torres Carrillo Josehf Miguel Angel   *
*       Tovar Jacuinde Rodrigo                *
*   Grupo                                     *
*       3CM13                                 *
*                                             *
**********************************************/

//Importamos las Bibliotecas necesarias para inicializar nuestra GUI
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

//Clase Principal para nuestra GUI que hace uso de la clase JFrame
public class GUI extends JFrame {

    //Variables para mostrar texto es nuestra aplicacion
    private JLabel titulo, inst1, inst2, inst3, inst4, inst5; 

    //Variables para botones que selecciona el archivo e inicia el cifrador
    private JButton selArchivo, iniciarCipher;

    //Variables para botones que indican si vamos a cifrar o a decifrar
    //junto con el grupo que solo permite seleccionar uno de estos a la vez
    private JRadioButton cifrar, descifrar;
    private ButtonGroup grupoRB;

    //Variables para botones que permiten seleccionar el modo en el que queremos
    //cifrar ademas del grupo que solo permite seleccionar uno a la vez
    private JRadioButton modoECB, modoCBC, modoCFB, modoOFB;
    private ButtonGroup grupoModos;

    //Variables para campos de texto donde podremos ingresar la llave y el 
    //vector de inicializacion si es necesario
    private JTextField llave, vectorC0;

    //Variable para agregar nuestra imagen de fondo para darle estilo a la GUI
    private JLabel fondo, imagenI, imagenD;
    private ImageIcon imagenicono;

    //Variable que nos permite obtener los metodos de nuestro archivo con las 
    //funciones para cifrar o descifrar nuestras imagenes
    private Utilidades entidad = new Utilidades();

    //Variables necesarias para obtener el contenido de la imagen a cifrar
    //la direccion de la imagen ademas de su nombre
    private byte[] bmpBytes;
    private String direccionArchivo;
    private String nombreArchivo;

    //Metodo de inicializacion de nuestra GUI
    public GUI (){

        //Mandamos a llamar nuestro metodo que inicializa nuestros elementos 
        //declarados para nuestra GUI
        iniciarComponentes();
    }

    //Metodo que inicializa nuestros componentes anteriormente
    private void iniciarComponentes (){

        //Creamos un objeto para nuestro titulo
        //y lo agregamos a nuestro JFrame para su visualizacion
        titulo = new JLabel();
        getContentPane().add(titulo);

        //Creamos un objeto para una nueva linea de texto
        //y lo agregamos a nuestro JFrame para su visualizacion
        inst1 = new JLabel();
        getContentPane().add(inst1);

        //Creamos un objeto para una nueva linea de texto
        //y lo agregamos a nuestro JFrame para su visualizacion
        inst2 = new JLabel();
        getContentPane().add(inst2);

        //Creamos un objeto para una nueva linea de texto
        //y lo agregamos a nuestro JFrame para su visualizacion
        inst3 = new JLabel();
        getContentPane().add(inst3);

        //Creamos un objeto para una nueva linea de texto
        //y lo agregamos a nuestro JFrame para su visualizacion
        inst4 = new JLabel();
        getContentPane().add(inst4);

        //Creamos un objeto para una nueva linea de texto
        //y lo agregamos a nuestro JFrame para su visualizacion
        inst5 = new JLabel();
        getContentPane().add(inst5);

        //Creamos un nuevo boton para seleccionar nuestro archivo
        //y le agregamos un metodo que 
        //responda a cada vez que se le de click
        //y al final agregamos nuestro boton a nuestra interfaz
        selArchivo = new JButton();
        selArchivo.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                selArchivoActionPerformed(evt);
            }
        });
        getContentPane().add(selArchivo);

        //Creamos un nuevo boton  para iniciar nuestro cifrador/Decifrador
        //y le agregamos un metodo que 
        //responda a cada vez que se le de click
        //y al final agregamos nuestro boton a nuestra interfaz
        iniciarCipher = new JButton();
        iniciarCipher.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent evt) {
                iniciarCipherActionPerformed(evt);
            }
        });
        getContentPane().add(iniciarCipher);

        //Inicializamos nuestro boton selector para la opcion de cifrar
        //y lo agregamos a nuestra interfaz grafica
        cifrar = new JRadioButton();
        getContentPane().add(cifrar);

        //Inicializamos nuestro boton selector para la opcion de decifrar
        //y lo agregamos a nuestra interfaz grafica
        descifrar = new JRadioButton();
        getContentPane().add(descifrar);

            //Creamos un nuevo grupo para nuestros botones selectores
            //esto con el objetivo de que solo uno se pueda seleccionar
            //a la vez, despues agregamos nuestros botones de cifrar y de
            //decifrar a nuestro nuevo grupo
            grupoRB = new ButtonGroup();
            grupoRB.add(cifrar);
            grupoRB.add(descifrar); 

        //Creamos un nuebo boton selector para nuestro modo de cifrado ECB
        //ademas de agregarle un metodo que responda cada vez que se le de
        //clic a nuestro boton selector
        modoECB = new JRadioButton();
        modoECB.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent evt) {
                modoDESActionPerformed(evt);
            }
        });
        getContentPane().add(modoECB);

        //Creamos un nuebo boton selector para nuestro modo de cifrado CBC
        //ademas de agregarle un metodo que responda cada vez que se le de
        //clic a nuestro boton selector
        modoCBC = new JRadioButton();
        modoCBC.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent evt) {
                modoDESActionPerformed(evt);
            }
        });
        getContentPane().add(modoCBC);

        //Creamos un nuebo boton selector para nuestro modo de cifrado CFB
        //ademas de agregarle un metodo que responda cada vez que se le de
        //clic a nuestro boton selector
        modoCFB = new JRadioButton();
        modoCFB.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent evt) {
                modoDESActionPerformed(evt);
            }
        });
        getContentPane().add(modoCFB);

        //Creamos un nuebo boton selector para nuestro modo de cifrado OFB
        //ademas de agregarle un metodo que responda cada vez que se le de
        //clic a nuestro boton selector
        modoOFB = new JRadioButton();
        modoOFB.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent evt) {
                modoDESActionPerformed(evt);
            }
        });
        getContentPane().add(modoOFB);

            //Agregamos nuestro nuevo grupo de boton que permite seleccionar 
            //un metodo de cifrado a la vez, para ello agregamos nuestros
            //botones de cifrado a neustro nuevo grupo
            grupoModos = new ButtonGroup();
            grupoModos.add(modoECB);
            grupoModos.add(modoCBC);
            grupoModos.add(modoCFB);
            grupoModos.add(modoOFB); 

        //Creamos un nuevo objeto de tipo campo de texto para insertar
        //nuestra llave, despues agregamos este campo a nuestro JFrame
        llave = new JTextField();
        getContentPane().add(llave);

        //Creamos un nuevo objeto de tipo campo de texto para insertar
        //nuestro vector de Inicializacion, despues agregamos este 
        //campo a nuestro JFrame
        vectorC0 = new JTextField();
        getContentPane().add(vectorC0);

        //Creamos un nuevo objeto para poder insertar una nueva imagen
        //dentro de nuestra aplicacion, posteriormente agregamos esta imagen
        //a nuestro JFrame
        imagenI = new JLabel();
        getContentPane().add(imagenI);

        //Creamos un nuevo objeto para poder insertar una nueva imagen
        //dentro de nuestra aplicacion, psteriormente agregamos esta imagen
        //a nuestro JFrame
        imagenD = new JLabel();
        getContentPane().add(imagenD);

        //Creamos un nuevo Label el cual tendra el color de fondo para nuestra
        //aplicacion, posteriormente agregaremos este fondo a nuestra aplicacion
        fondo = new JLabel();
        getContentPane().add(fondo);

        //Creamos un nuevo icono que se insertara en nuestro Label de imagenes
        //este objeto no se insertara como tal en nuestro JFrame
        imagenicono = new ImageIcon("fondo.png");

        //Creamos nuestro panel para poder mostrarlo en pantalla
        getContentPane().setLayout(null);

        //Aqui definimos el tamaño de ventana para nuestra aplicacion
        setSize(800, 600);

        //Definimos la aplicacion para que se habra en nuestro monitor
        //principal de manera centrada
        setLocationRelativeTo(null);

        //Definimos la operacion de cierre para que cada vez que se cerremos
        //la aplicacion esta detenga el proceso
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        //Definimos como visible nuestro panel con nuestros objetos 
        setVisible(true);

        //Mandamos nuestro objeto para ejecutar nuestra GUI
        iniciarGUI();
    }

    //Metodo para ejecutar nuestros componentes para nuestro JFrame
    //ademas de darle propiedades a cada uno
    public void iniciarGUI (){

        //Para nuestro titulo lo que haremos sera darle el texto que queremos
        //que muestre dentro de nuestra aplicacion con setText
        titulo.setText("Practica 1 - 3CM13");

        //Le daremos estilo a la tipografia que muestra nuestro titulo
        titulo.setFont(new Font("Serif", Font.BOLD, 50));

        //Por ultimo asignaremos la ubicacion dentro de nuestra ventana 
        //a nuestro titulo mediante setBounds
        titulo.setBounds(180, 10, 430, 50);

        //Al igual que nuestro titulo lo que haremos sera asignarle texto a 
        //nuestro JLabel, un estilo para su tipografia ademas de su ubicacion
        //en nuestra aplicacion
        inst1.setText("Seleccione un Archivo");
        inst1.setFont(new Font("Serif", Font.BOLD, 30));
        inst1.setBounds(30, 80, 280, 30);

            //A diferencia de nuestros titulos anteriores lo que haremos sera 
            //asignarle un color de fondo a blanco para tener una apariencia
            //mas limpia generalmente
            selArchivo.setText("Seleccionar");
            selArchivo.setBackground(Color.white);
            selArchivo.setFont(new Font("Serif", Font.BOLD, 20));
            selArchivo.setBounds(520, 85, 140, 25);

        //Al igual que en nuestros elementos anteriores lo que haremos sera 
        //asignarle texto a nuestro JLabel, un estilo para su tipografia 
        //ademas de su ubicacion en nuestra aplicacion
        inst2.setText("Seleccione la Opcion Deseada");
        inst2.setFont(new Font("Serif", Font.BOLD, 30));
        inst2.setBounds(30, 130, 380, 40);

            //Al igual que el boton para seleccionar archivo haremos la
            //asignacion de texto, color de fondo, tipografia y posicion
            cifrar.setText("Cifrar");
            cifrar.setBackground(Color.white);
            cifrar.setFont(new Font("Serif", Font.BOLD, 25));
            cifrar.setBounds(450, 140, 100, 25);

            //Al igual que en botones anteriores lo que sera la
            //asignacion de texto, color de fondo, tipografia y posicion
            descifrar.setText("Descifrar");
            descifrar.setBackground(Color.white);
            descifrar.setFont(new Font("Serif", Font.BOLD, 25));
            descifrar.setBounds(580, 140, 140, 25);

        //Al igual que en nuestros elementos anteriores lo que haremos sera 
        //asignarle texto a nuestro JLabel, un estilo para su tipografia 
        //ademas de su ubicacion en nuestra aplicacion
        inst3.setText("Seleccione el modo de Cifrado/Descifrado");
        inst3.setFont(new Font("Serif", Font.BOLD, 30));
        inst3.setBounds(30, 190, 600, 30);

            //Al igual que en botones anteriores lo que sera la
            //asignacion de texto, color de fondo, tipografia y posicion
            modoECB.setText("ECB");
            modoECB.setBackground(Color.white);
            modoECB.setFont(new Font("Serif", Font.BOLD, 25));
            modoECB.setBounds(50, 230, 100, 30);

            //Al igual que en botones anteriores lo que sera la
            //asignacion de texto, color de fondo, tipografia y posicion
            modoCBC.setText("CBC");
            modoCBC.setBackground(Color.white);
            modoCBC.setFont(new Font("Serif", Font.BOLD, 25));
            modoCBC.setBounds(150, 230, 100, 30);

            //Al igual que en botones anteriores lo que sera la
            //asignacion de texto, color de fondo, tipografia y posicion
            modoCFB.setText("CFB");
            modoCFB.setBackground(Color.white);
            modoCFB.setFont(new Font("Serif", Font.BOLD, 25));
            modoCFB.setBounds(250, 230, 100, 30);

            //Al igual que en botones anteriores lo que sera la
            //asignacion de texto, color de fondo, tipografia y posicion
            modoOFB.setText("OFB");
            modoOFB.setBackground(Color.white);
            modoOFB.setFont(new Font("Serif", Font.BOLD, 25));
            modoOFB.setBounds(350, 230, 100, 30);

        //Al igual que en nuestros elementos anteriores lo que haremos sera 
        //asignarle texto a nuestro JLabel, un estilo para su tipografia 
        //ademas de su ubicacion en nuestra aplicacion
        inst4.setText("Ingresar llave Deseada (8 Bits)");
        inst4.setFont(new Font("Serif", Font.BOLD, 30));
        inst4.setBounds(30, 270, 400, 40);

            //Para nuestros campos de texto lo que haremos sera asignar nuestro
            //color de fondo a blanco ademas de asignarle un tipo de tipografia
            //y su posicion en nuestra aplicacion
            llave.setBackground(Color.white);            
            llave.setFont(new Font("Serif", Font.BOLD, 30));
            llave.setBounds(550, 270, 200, 40);

        //Al igual que en nuestros elementos anteriores lo que haremos sera 
        //asignarle texto a nuestro JLabel, un estilo para su tipografia 
        //ademas de su ubicacion en nuestra aplicacion
        inst5.setText("Ingresar Vector de Inicializacion (8 Bits)");
        inst5.setFont(new Font("Serif", Font.BOLD, 30));
        inst5.setBounds(30, 330, 540, 40);


            //Al igual que en nuestro campo de la llave lo que haremos sera
            //poner el fondo de color blanco, una tipografia ademas de su
            //posicion dentro de nuestra aplicacion
            vectorC0.setBackground(Color.white);            
            vectorC0.setFont(new Font("Serif", Font.BOLD, 30));
            vectorC0.setBounds(550, 330, 200, 40);

        //Al igual que en botones anteriores lo que sera la
        //asignacion de texto, color de fondo, tipografia y posicion
        iniciarCipher.setText("Iniciar Proceso");
        iniciarCipher.setBackground(Color.white);
        iniciarCipher.setFont(new Font("Serif", Font.BOLD, 30));
        iniciarCipher.setBounds(240, 400, 300, 30);

        //Para poner nuestras imagenes lo que haremos sera poner nuestro 
        //icono a nuestro JLabel ademas de poner su posicion dentro de nuestra
        //aplicacion para su visualizacion
        imagenI.setIcon(imagenicono);
        imagenI.setBounds(20, 340, 300, 236);

        //Haremos lo mismo para nuestra segunda imagen, asignaremos la imagen
        //que tendra ademas de su posicion
        imagenD.setIcon(imagenicono);
        imagenD.setBounds(550, 340, 300, 236);

        //Finalmente agregaremos nuestro color de fondo para nuestra aplicacion
        //asignaremos el color blanco a nuestro fondo, y lo haremos del tamaño
        //de nuestra aplicacion, ademas de poner el fondo con la opacidad en true
        fondo.setBackground(Color.white);
        fondo.setBounds(0, 0, 800, 600);
        fondo.setOpaque(true);
    }

    //Metodo para nuestro botones de seleccion para modo de cifrado
    private void modoDESActionPerformed (ActionEvent evt) {

        //En caso de que nuestro modo de cifrado sea igual a ECB lo que
        //haremos sera deshabilitar el campo del vector de inicializacion
        //ya que este no es necesario en este modo, en cambio si nuestro
        //modo es alguno de los otros 3 lo que haremo sera activar nuestro
        //campo de vector de inicializacion
        if (modoECB.isSelected()==true) vectorC0.setEditable(false);
        else vectorC0.setEditable(true);
    }

    //Metodo para nuestro boton de seleccion de archivo
    private void selArchivoActionPerformed(ActionEvent evt) {

        //Insertamos nuestro codigo en un bloque try-catch por que puede
        //presentar excepciones en su ejecucion
        try{ 

            //Madamos a llamar a nuestro metodo de obtener directorio
            //para obtener la ubicacion del archivo
            direccionArchivo =  entidad.obtenerDireccionArchivo();

            //Una vez obtenida la ubicacion de nuestro archivo lo que haremos
            //es obtener el nombre de nuestro archivo, eliminando la direccion
            //de las subcarpetas en la direccion
            nombreArchivo = direccionArchivo.substring(direccionArchivo.lastIndexOf("\\") + 1).replaceFirst("[.^][^.]+$", "");
            
            //Lo que haremos despues sera a llamar a nuestro metodo leer archivo
            //el cual retornara el contenido del archivo en nuestra cadena de bytes
            bmpBytes = entidad.leerArchivo(direccionArchivo);
        }
        catch(Exception error){

            //Si no abrimos ningun archivo o este mismo tiene un error lo que haremos sera mandar una alerta
            JOptionPane.showMessageDialog(null, "Error al leer el Archivo");
        }
    }

    //Metodo que responde al boton de iniciar proceso que ejecutara el metodo
    //principal para cifrar o descifrar nuestro archivo
    private void iniciarCipherActionPerformed(ActionEvent evt) {

        //Encerramos nuestros metodo en un bloque try por que puede arrojar
        //excepciones een caso de errores
        try{

            //Si el boton de cifrar esta seleccionado lo que haremos sera mandar a llamar a nuestro metodo en modo de cifrado
            if (cifrar.isSelected() == true){

                //Ahora dependiendo del modo de operacion que deseemos mandaremos los parametros correpondientes:

                //Si nuesxtro modo de cifrado es ECB lo que haremos sera mandar como parametro nuestra variable con los datos de nuestro
                //archivo a cifrar, el texto que se haya ingresado en nuestro campo de llave, el modo de operacion que realizaremos
                //ademas de el nombre de nuestro archivo para posteriormente asignarle el nomnre correspondiente
                if (modoECB.isSelected() == true) 
                    entidad.cifradoDescifrado(bmpBytes, llave.getText(), "", "DES/ECB/NoPadding", "Cifrar", nombreArchivo);

                //En los demas casos lo que haremos sera mandar exatamente los mismos parametros pero de manera alternativa lo que haremos
                //sera enviar el vector de inicializacion
                if (modoCBC.isSelected() == true) 
                    entidad.cifradoDescifrado(bmpBytes, llave.getText(), vectorC0.getText(), "DES/CBC/NoPadding", "Cifrar", nombreArchivo);
                if (modoCFB.isSelected() == true) 
                    entidad.cifradoDescifrado(bmpBytes, llave.getText(), vectorC0.getText(), "DES/CFB/NoPadding", "Cifrar", nombreArchivo);
                if (modoOFB.isSelected() == true) 
                    entidad.cifradoDescifrado(bmpBytes, llave.getText(), vectorC0.getText(), "DES/OFB/NoPadding", "Cifrar", nombreArchivo);                
            }

            //Para el modo de descifrado haremos exactamente lo mismo que en nuestro modo de cifrado, mandaremos los mismos parametros a 
            //la misma funcion, siendo el modo ECB el unico sin vector de inicializacion
            if (descifrar.isSelected() == true){

                if (modoECB.isSelected() == true) 
                    entidad.cifradoDescifrado(bmpBytes, llave.getText(), "", "DES/ECB/NoPadding", "Descifrar", nombreArchivo);
                if (modoCBC.isSelected() == true) 
                    entidad.cifradoDescifrado(bmpBytes, llave.getText(), vectorC0.getText(), "DES/CBC/NoPadding", "Descifrar", nombreArchivo);
                if (modoCFB.isSelected() == true) 
                    entidad.cifradoDescifrado(bmpBytes, llave.getText(), vectorC0.getText(), "DES/CFB/NoPadding", "Descifrar", nombreArchivo);
                if (modoOFB.isSelected() == true) 
                    entidad.cifradoDescifrado(bmpBytes, llave.getText(), vectorC0.getText(), "DES/OFB/NoPadding", "Descifrar", nombreArchivo);
            }                
        }
        catch(Exception error) {

            //En caso de que exista un error en el cifrado o descifrado o algunos de los parametros no es correcto lo que haremos
            //sera mandar nun mensaje de alerta al usuario
            JOptionPane.showMessageDialog(null, "Error al inicializar el proceso");
        }            
    }
}
