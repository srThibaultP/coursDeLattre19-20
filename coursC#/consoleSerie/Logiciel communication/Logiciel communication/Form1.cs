using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            richTextBox2.Text = serialPort1.ReadLine();
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {
            serialPort1.WriteLine(richTextBox1.Text + "\r");
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            serialPort1.BaudRate = 9600;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.Open();
            button1.Enabled = false;
            button2.Enabled = true;
            button4.Text = "Ouvert";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            serialPort1.Close();
            button1.Enabled = true;
            button2.Enabled = false;
            button4.Text = "Fermé";
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            serialPort1.BaudRate = 19600;
        }

        private void richTextBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            //serialPort1.Close();
            Close();
        }

        private void button4_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    }
}
