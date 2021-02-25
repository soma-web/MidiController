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
            this.panel1 = new System.Windows.Forms.Panel();
            this.lbDeviceName = new System.Windows.Forms.Label();
            this.lbDeviceNameLabel = new System.Windows.Forms.Label();
            this.lbConnectionStatus = new System.Windows.Forms.Label();
            this.lbConnectionStatusLabel = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.btSync = new System.Windows.Forms.Button();
            this.btReconnect = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
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
            this.btConfig.Location = new System.Drawing.Point(12, 210);
            this.btConfig.Name = "btConfig";
            this.btConfig.Size = new System.Drawing.Size(98, 36);
            this.btConfig.TabIndex = 0;
            this.btConfig.Text = "Config Folder";
            this.btConfig.UseVisualStyleBackColor = true;
            // 
            // panelMidiIn
            // 
            this.panelMidiIn.Location = new System.Drawing.Point(50, 6);
            this.panelMidiIn.Name = "panelMidiIn";
            this.panelMidiIn.Size = new System.Drawing.Size(17, 17);
            this.panelMidiIn.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(3, 10);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Midi In:";
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.lbDeviceName);
            this.panel1.Controls.Add(this.lbDeviceNameLabel);
            this.panel1.Controls.Add(this.lbConnectionStatus);
            this.panel1.Controls.Add(this.lbConnectionStatusLabel);
            this.panel1.Location = new System.Drawing.Point(15, 25);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(211, 44);
            this.panel1.TabIndex = 3;
            // 
            // lbDeviceName
            // 
            this.lbDeviceName.AutoSize = true;
            this.lbDeviceName.Location = new System.Drawing.Point(111, 20);
            this.lbDeviceName.MinimumSize = new System.Drawing.Size(100, 0);
            this.lbDeviceName.Name = "lbDeviceName";
            this.lbDeviceName.Size = new System.Drawing.Size(100, 13);
            this.lbDeviceName.TabIndex = 3;
            this.lbDeviceName.Text = "sadsdasd";
            this.lbDeviceName.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lbDeviceNameLabel
            // 
            this.lbDeviceNameLabel.AutoSize = true;
            this.lbDeviceNameLabel.Location = new System.Drawing.Point(4, 20);
            this.lbDeviceNameLabel.Name = "lbDeviceNameLabel";
            this.lbDeviceNameLabel.Size = new System.Drawing.Size(72, 13);
            this.lbDeviceNameLabel.TabIndex = 2;
            this.lbDeviceNameLabel.Text = "Device Name";
            this.lbDeviceNameLabel.Click += new System.EventHandler(this.lbDeviceNameLabel_Click);
            // 
            // lbConnectionStatus
            // 
            this.lbConnectionStatus.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.lbConnectionStatus.AutoSize = true;
            this.lbConnectionStatus.Location = new System.Drawing.Point(111, 4);
            this.lbConnectionStatus.MinimumSize = new System.Drawing.Size(100, 0);
            this.lbConnectionStatus.Name = "lbConnectionStatus";
            this.lbConnectionStatus.Size = new System.Drawing.Size(100, 13);
            this.lbConnectionStatus.TabIndex = 1;
            this.lbConnectionStatus.Text = "asdasdasd";
            this.lbConnectionStatus.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lbConnectionStatusLabel
            // 
            this.lbConnectionStatusLabel.AutoSize = true;
            this.lbConnectionStatusLabel.Location = new System.Drawing.Point(4, 4);
            this.lbConnectionStatusLabel.Name = "lbConnectionStatusLabel";
            this.lbConnectionStatusLabel.Size = new System.Drawing.Size(91, 13);
            this.lbConnectionStatusLabel.TabIndex = 0;
            this.lbConnectionStatusLabel.Text = "ConnectionStatus";
            this.lbConnectionStatusLabel.Click += new System.EventHandler(this.lbConnectionStatusLabel_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(37, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Status";
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.label1);
            this.panel2.Controls.Add(this.panelMidiIn);
            this.panel2.Location = new System.Drawing.Point(15, 85);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(109, 27);
            this.panel2.TabIndex = 0;
            // 
            // btSync
            // 
            this.btSync.Location = new System.Drawing.Point(15, 130);
            this.btSync.Name = "btSync";
            this.btSync.Size = new System.Drawing.Size(95, 34);
            this.btSync.TabIndex = 5;
            this.btSync.Text = "Sync ";
            this.btSync.UseVisualStyleBackColor = true;
            this.btSync.Click += new System.EventHandler(this.btSync_Click);
            // 
            // btReconnect
            // 
            this.btReconnect.Location = new System.Drawing.Point(15, 170);
            this.btReconnect.Name = "btReconnect";
            this.btReconnect.Size = new System.Drawing.Size(95, 34);
            this.btReconnect.TabIndex = 6;
            this.btReconnect.Text = "Reconncet";
            this.btReconnect.UseVisualStyleBackColor = true;
            // 
            // VoiceMeterMidi
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(303, 339);
            this.Controls.Add(this.btReconnect);
            this.Controls.Add(this.btSync);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.btConfig);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.KeyPreview = true;
            this.Name = "VoiceMeterMidi";
            this.Text = "VoiceMeterMidi";
            this.Resize += new System.EventHandler(this.OnResize);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.NotifyIcon notifyIcon1;
        private System.Windows.Forms.Button btConfig;
        private System.Windows.Forms.Panel panelMidiIn;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label lbConnectionStatus;
        private System.Windows.Forms.Label lbConnectionStatusLabel;
        private System.Windows.Forms.Label lbDeviceName;
        private System.Windows.Forms.Label lbDeviceNameLabel;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button btSync;
        private System.Windows.Forms.Button btReconnect;
    }
}

