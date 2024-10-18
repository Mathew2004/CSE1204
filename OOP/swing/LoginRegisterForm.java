import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class LoginRegisterForm extends JFrame {
    // Database connection
    private Connection connection;
    
    // Constructor to set up GUI
    public LoginRegisterForm() {
        // Establish the database connection
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection("jdbc:mysql://localhost:8080/user_db", "root", "password"); // Change to your own credentials
            System.out.println("Connected to DB");
        } catch (Exception e) {
            e.printStackTrace();
        }

        // GUI setup
        setTitle("Login/Register Form");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        
        // Main panel
        JPanel panel = new JPanel();
        panel.setLayout(new CardLayout());

        // Create Login panel
        JPanel loginPanel = createLoginPanel(panel);
        panel.add(loginPanel, "Login");

        // Create Register panel
        JPanel registerPanel = createRegisterPanel(panel);
        panel.add(registerPanel, "Register");

        add(panel);
        setVisible(true);
    }

    // Create login panel
    private JPanel createLoginPanel(JPanel parentPanel) {
        JPanel panel = new JPanel(new GridLayout(4, 2, 10, 10));

        JLabel usernameLabel = new JLabel("Username:");
        JTextField usernameField = new JTextField();
        JLabel passwordLabel = new JLabel("Password:");
        JPasswordField passwordField = new JPasswordField();

        JButton loginButton = new JButton("Login");
        JButton switchToRegister = new JButton("Register");

        loginButton.addActionListener(e -> {
            String username = usernameField.getText();
            String password = String.valueOf(passwordField.getPassword());
            if (login(username, password)) {
                JOptionPane.showMessageDialog(this, "Login successful!");
            } else {
                JOptionPane.showMessageDialog(this, "Invalid credentials.");
            }
        });

        switchToRegister.addActionListener(e -> {
            CardLayout layout = (CardLayout) parentPanel.getLayout();
            layout.show(parentPanel, "Register");
        });

        panel.add(usernameLabel);
        panel.add(usernameField);
        panel.add(passwordLabel);
        panel.add(passwordField);
        panel.add(loginButton);
        panel.add(switchToRegister);

        return panel;
    }

    // Create register panel
    private JPanel createRegisterPanel(JPanel parentPanel) {
        JPanel panel = new JPanel(new GridLayout(4, 2, 10, 10));

        JLabel usernameLabel = new JLabel("Username:");
        JTextField usernameField = new JTextField();
        JLabel passwordLabel = new JLabel("Password:");
        JPasswordField passwordField = new JPasswordField();

        JButton registerButton = new JButton("Register");
        JButton switchToLogin = new JButton("Login");

        registerButton.addActionListener(e -> {
            String username = usernameField.getText();
            String password = String.valueOf(passwordField.getPassword());
            if (register(username, password)) {
                JOptionPane.showMessageDialog(this, "Registration successful!");
            } else {
                JOptionPane.showMessageDialog(this, "Registration failed. User might already exist.");
            }
        });

        switchToLogin.addActionListener(e -> {
            CardLayout layout = (CardLayout) parentPanel.getLayout();
            layout.show(parentPanel, "Login");
        });

        panel.add(usernameLabel);
        panel.add(usernameField);
        panel.add(passwordLabel);
        panel.add(passwordField);
        panel.add(registerButton);
        panel.add(switchToLogin);

        return panel;
    }

    // Method to handle login
    private boolean login(String username, String password) {
        try {
            String query = "SELECT * FROM users WHERE username=? AND password=?";
            PreparedStatement pst = connection.prepareStatement(query);
            pst.setString(1, username);
            pst.setString(2, password);
            ResultSet rs = pst.executeQuery();
            return rs.next();
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
    }

    // Method to handle registration
    private boolean register(String username, String password) {
        try {
            String query = "INSERT INTO users (username, password) VALUES (?, ?)";
            PreparedStatement pst = connection.prepareStatement(query);
            pst.setString(1, username);
            pst.setString(2, password);
            pst.executeUpdate();
            return true;
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
    }

    // Main method
    public static void main(String[] args) {
        SwingUtilities.invokeLater(LoginRegisterForm::new);
    }
}
