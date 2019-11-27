using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Affichage_Capteurs
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            string RxString;
            char car;
            RxString = serialPort1.ReadLine();

            if (RxString != "\n")
            {
                if ((RxString[0] == 'L') && (RxString[1] == 'M'))
                {
                    textBox1.Text = "";

                    for (int i = 2; i < 4; i++)
                    {
                        car = RxString[i];
                        textBox1.Text = textBox1.Text + car; // affichage de la temperature dans  textBox1
                    }
                    textBox1.Text = textBox1.Text+ "°C\r";
                }
                else if ((RxString[0] == 'D') && (RxString[1] == 'S'))
                {
                    textBox2.Text = "";

                    for (int i = 2; i < 5; i++)
                    {
                        car = RxString[i];
                        textBox2.Text = textBox2.Text + car + "Â°C\r"; // affichage de la temperature dans  textBox1
                    }
                }
                else if ((RxString[0] == 'T') && (RxString[1] == 'C'))
                {
                    textBox3.Text = "";

                    for (int i = 2; i < 5; i++)
                    {
                        car = RxString[i];
                        textBox3.Text = textBox3.Text + car + "Â°C\r"; // affichage de la temperature dans  textBox1
                    }
                }
            }
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.Open();
            button1.Enabled = false;
            button2.Enabled = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            serialPort1.Close();
            button1.Enabled = true;
            button2.Enabled = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFile1 = new SaveFileDialog();
            saveFile1.DefaultExt = "*.ods"; // Extension du fichier
            saveFile1.Filter = "ods (*.ods)|*.ods";
            if (saveFile1.ShowDialog() == System.Windows.Forms.DialogResult.OK && saveFile1.FileName.Length > 0)
            {
                richTextBox1.SaveFile(saveFile1.FileName);
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedItem.Equals("COM1"))
            {
                serialPort1.PortName = "COM1"; // Ici choix de COM5

            }
            if (listBox1.SelectedItem.Equals("COM2"))
            {
                serialPort1.PortName = "COM2"; // Ici choix de COM5

            }
            if (listBox1.SelectedItem.Equals("COM3"))
            {
                serialPort1.PortName = "COM3"; // Ici choix de COM5

            }
            if (listBox1.SelectedItem.Equals("COM4"))
            {
                serialPort1.PortName = "COM4"; // Ici choix de COM5

            }
            if (listBox1.SelectedItem.Equals("COM5"))
            {
                serialPort1.PortName = "COM5"; // Ici choix de COM5

            }
            if (listBox1.SelectedItem.Equals("COM6"))
            {
                serialPort1.PortName = "COM6"; // Ici choix de COM5

            }
            if (listBox1.SelectedItem.Equals("COM7"))
            {
                serialPort1.PortName = "COM7"; // Ici choix de COM5

            }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked == true)
            {
                serialPort1.WriteLine("D8 \r");
            }
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox2.Checked == true)
            {
                serialPort1.WriteLine("D7 \r");
            }
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox3.Checked == true)
            {
                serialPort1.WriteLine("D6 \r");
            }
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
           if( checkBox4.Checked==true){
            serialPort1.WriteLine("D5 \r");
               }
        }

        private void checkBox5_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox5.Checked == true)
            {
                serialPort1.WriteLine("D4 \r");
            }
        }

        private void checkBox6_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox6.Checked == true)
            {
                serialPort1.WriteLine("D3 \r");
            }
        }

        private void checkBox7_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox7.Checked == true)
            {
                serialPort1.WriteLine("D2 \r");
            }
        }

        private void checkBox8_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox8.Checked == true)
            {
                serialPort1.WriteLine("D1 \r");
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            
        }

    }
}
