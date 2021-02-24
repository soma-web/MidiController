namespace MidiRemoteWindowsAppliaction
{
    partial class VoiceMeterMidi
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(VoiceMeterMidi));
            this.notifyIcon1 = new System.Windows.Forms.NotifyIcon(this.components);
            this.btConfig = new System.Windows.Forms.Button();
            this.panelMidiIn = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // notifyIcon1
            // 
            this.notifyIcon1.BalloonTipText = "VoiceMeter Midi Controller";
            this.notifyIcon1.BalloonTipTitle = "VoiceMeter Midi Controller";
            this.notifyIcon1.Icon = ((System.Drawing.Icon)(resources.GetObject("notifyIcon1.Icon")));
            this.notifyIcon1.Text = "VoiceMeter Midi Controller";
            this.notifyIcon1.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.OnNotifyDoubleClick);
            // 
            // btConfig
            // 
            this.btConfig.Location = new System.Drawing.Point(12, 48);
            this.btConfig.Name = "btConfig";
            this.btConfig.Size = new System.Drawing.Size(93, 36);
            this.btConfig.TabIndex = 0;
            this.btConfig.Text = "Config Folder";
            this.btConfig.UseVisualStyleBackColor = true;
            // 
            // panelMidiIn
            // 
            this.panelMidiIn.Location = new System.Drawing.Point(69, 14);
            this.panelMidiIn.Name = "panelMidiIn";
            this.panelMidiIn.Size = new System.Drawing.Size(17, 17);
            this.panelMidiIn.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(22, 18);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Midi In:";
            // 
            // VoiceMeterMidi
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(294, 96);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.panelMidiIn);
            this.Controls.Add(this.btConfig);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.KeyPreview = true;
            this.Name = "VoiceMeterMidi";
            this.Text = "VoiceMeterMidi";           
            this.Resize += new System.EventHandler(this.OnResize);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.NotifyIcon notifyIcon1;
        private System.Windows.Forms.Button btConfig;
        private System.Windows.Forms.Panel panelMidiIn;
        private System.Windows.Forms.Label label1;
    }
}

