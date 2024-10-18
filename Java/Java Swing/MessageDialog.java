import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;


class MessageDialog{
    public static void main(String[] args) {
        ImageIcon icon = new ImageIcon("sponsor.png");
        // JOptionPane.showMessageDialog(null, "Hi there","error", JOptionPane.ERROR_MESSAGE, icon);

    // Input
        // String name = JOptionPane.showInputDialog(null,"Who are you?", "Title ",JOptionPane.QUESTION_MESSAGE);
        // JOptionPane.showMessageDialog(null, "Welcome, "+name);
    
    // COnfirm 
    // int choice = JOptionPane.showConfirmDialog(null, "DO you want to exist? ", "Quit?", JOptionPane.YES_NO_OPTION);
    
    // if(choice == JOptionPane.YES_OPTION){
    //     System.out.println("Exiting");
    //     System.exit(0);
    // }else{
    //     System.out.println("Okay");
    // }


    // Creating JFrame
    JFrame frame = new JFrame();
    frame.setVisible(true);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setSize(300, 200);
    frame.setBounds(200,200,300,400);
    frame.setTitle("My First Frame");
    frame.setIconImage(icon.getImage());
    // Center this frame
    frame.setLocationRelativeTo(null);

    JButton btn = new JButton();
    
    btn.setText("Click Me");
    // frame.add(btn);
    btn.setBounds(100,200, 50,20);
    frame.add(btn);

    }

}