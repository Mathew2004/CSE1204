import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class CircleResizeApp extends JFrame {
    private int circleDiameter = 100;
    private final int DIAMETER_STEP = 10;

    public CircleResizeApp() {
        setTitle("Circle Re-sizer");
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Panel for the circle
        CirclePanel circlePanel = new CirclePanel();
        add(circlePanel, BorderLayout.CENTER);

        // Panel for the buttons
        JPanel buttonPanel = new JPanel();
        JButton enlargeButton = new JButton("+");
        JButton shrinkButton = new JButton("-");

        enlargeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                circleDiameter += DIAMETER_STEP;
                circlePanel.repaint();
            }
        });

        shrinkButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                circleDiameter -= DIAMETER_STEP;
                if (circleDiameter < 10) {
                    circleDiameter = 10;  // Prevent the circle from disappearing
                }
                circlePanel.repaint();
            }
        });

        buttonPanel.add(enlargeButton);
        buttonPanel.add(shrinkButton);
        add(buttonPanel, BorderLayout.SOUTH);
    }

    private class CirclePanel extends JPanel {
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            int x = (getWidth() - circleDiameter) / 2;
            int y = (getHeight() - circleDiameter) / 2;
            g.setColor(Color.RED);
            g.fillOval(x, y, circleDiameter, circleDiameter);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            CircleResizeApp app = new CircleResizeApp();
            app.setVisible(true);
        });
    }
}