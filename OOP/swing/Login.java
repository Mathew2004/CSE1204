import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.event.ActionListener;

class MyFrame3 extends JFrame implements ActionListener{
 Container c;
 JLabel lblusername=new JLabel();
 JLabel lblpassword=new JLabel();
 JLabel lblphn=new JLabel();
 JTextField txtusername=new JTextField();
 JPasswordField txtpassword=new JPasswordField();
 JTextField txtphn=new JTextField();
 JButton btnsubmit=new JButton();
 JButton btnclear=new JButton();

 JLabel lbldisplay=new JLabel();

   public MyFrame3(){
      c=getContentPane();
      c.setLayout(null);
      //for labels-1
      lblusername.setBounds(100,100,80,40);
      lblusername.setText("Username ");
      c.add(lblusername);
      //for username input
      txtusername.setBounds(185,100,150,40);
      c.add(txtusername);

       //for labels-2
       lblpassword.setBounds(100,150,80,40);
       lblpassword.setText("Password ");
       c.add(lblpassword);
       //for username input
       txtpassword.setBounds(185,150,150,40);
       c.add(txtpassword);
       txtphn.setBounds(185,150,150,40);
       c.add(txtphn);

       //submit button
       btnsubmit.setBounds(200,200,90,40);
       btnsubmit.setText("Submit");
       c.add(btnsubmit);
       //clear button
       btnclear.setBounds(293,200,90,40);
       btnclear.setText("Clear");
       c.add(btnclear);
       btnsubmit.addActionListener(this);
       //display label
       lbldisplay.setBounds(250,260,150,40);
       lbldisplay.setText("Welcome");
       c.add(lbldisplay);
       btnclear.addActionListener(this);

 }  //end of constructor
  public void actionPerformed(ActionEvent e){
    String u=new String(txtusername.getText());
    String p=new String(txtpassword.getPassword());
    if(e.getSource()==btnsubmit){
      if(u.equals("evan")){
        //valid username
        if(p.equals("1234")){
            //both username and password valid
            lbldisplay.setText("Valid User");
            JOptionPane.showMessageDialog(this, "Valid User");
        }
         
        else{
            //invalid password
            lbldisplay.setText("Invalid Password"); 
            JOptionPane.showMessageDialog(this, "Invalid User");   
        }
      }
         
      else{
        //invalide username
        lbldisplay.setText("Invalid Username");
        JOptionPane.showMessageDialog(this, "Invalid User");  
      }
    }
   
    else if(e.getSource() == btnclear){
      
      JOptionPane.showMessageDialog(this, "Clear Slama");
    }


  }

}


public class Login {
    public static void main(String[] args) {
     MyFrame3 frame3=new MyFrame3();
     frame3.setBounds(100,100,500,400);   
     frame3.setVisible(true);  
     frame3.setTitle("CSE 1203"); 
     frame3.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
           
    }
    

}