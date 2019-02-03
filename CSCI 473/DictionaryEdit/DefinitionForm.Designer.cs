namespace DictionaryEdit
{
    partial class DefinitionForm
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.defHeadBox = new System.Windows.Forms.TextBox();
            this.defPOSBox = new System.Windows.Forms.ComboBox();
            this.addIllBtn = new System.Windows.Forms.Button();
            this.defSDefBox = new System.Windows.Forms.TextBox();
            this.defDefBox = new System.Windows.Forms.TextBox();
            this.okBtn = new System.Windows.Forms.Button();
            this.cnclBtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(59, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "HeadWord";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(13, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "POS";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(13, 83);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(79, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Short Definition";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(13, 122);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(51, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Definition";
            // 
            // defHeadBox
            // 
            this.defHeadBox.Location = new System.Drawing.Point(102, 15);
            this.defHeadBox.Name = "defHeadBox";
            this.defHeadBox.ReadOnly = true;
            this.defHeadBox.Size = new System.Drawing.Size(383, 20);
            this.defHeadBox.TabIndex = 4;
            // 
            // defPOSBox
            // 
            this.defPOSBox.FormattingEnabled = true;
            this.defPOSBox.Items.AddRange(new object[] {
            "adj.",
            "adv.",
            "conj.",
            "ideo.",
            "prep.",
            "pro.",
            "n.",
            "v."});
            this.defPOSBox.Location = new System.Drawing.Point(102, 48);
            this.defPOSBox.Name = "defPOSBox";
            this.defPOSBox.Size = new System.Drawing.Size(383, 21);
            this.defPOSBox.TabIndex = 5;
            // 
            // addIllBtn
            // 
            this.addIllBtn.Location = new System.Drawing.Point(500, 15);
            this.addIllBtn.Name = "addIllBtn";
            this.addIllBtn.Size = new System.Drawing.Size(100, 23);
            this.addIllBtn.TabIndex = 6;
            this.addIllBtn.Text = "Add Illustrations";
            this.addIllBtn.UseVisualStyleBackColor = true;
            this.addIllBtn.Click += new System.EventHandler(this.addIllBtn_Click);
            // 
            // defSDefBox
            // 
            this.defSDefBox.Location = new System.Drawing.Point(102, 83);
            this.defSDefBox.Name = "defSDefBox";
            this.defSDefBox.Size = new System.Drawing.Size(573, 20);
            this.defSDefBox.TabIndex = 7;
            // 
            // defDefBox
            // 
            this.defDefBox.Location = new System.Drawing.Point(102, 122);
            this.defDefBox.Multiline = true;
            this.defDefBox.Name = "defDefBox";
            this.defDefBox.Size = new System.Drawing.Size(573, 89);
            this.defDefBox.TabIndex = 8;
            // 
            // okBtn
            // 
            this.okBtn.Location = new System.Drawing.Point(705, 122);
            this.okBtn.Name = "okBtn";
            this.okBtn.Size = new System.Drawing.Size(75, 23);
            this.okBtn.TabIndex = 9;
            this.okBtn.Text = "OK";
            this.okBtn.UseVisualStyleBackColor = true;
            this.okBtn.Click += new System.EventHandler(this.okBtn_Click);
            // 
            // cnclBtn
            // 
            this.cnclBtn.Location = new System.Drawing.Point(705, 167);
            this.cnclBtn.Name = "cnclBtn";
            this.cnclBtn.Size = new System.Drawing.Size(75, 23);
            this.cnclBtn.TabIndex = 10;
            this.cnclBtn.Text = "Cancel";
            this.cnclBtn.UseVisualStyleBackColor = true;
            this.cnclBtn.Click += new System.EventHandler(this.cnclBtn_Click);
            // 
            // DefinitionForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(798, 258);
            this.Controls.Add(this.cnclBtn);
            this.Controls.Add(this.okBtn);
            this.Controls.Add(this.defDefBox);
            this.Controls.Add(this.defSDefBox);
            this.Controls.Add(this.addIllBtn);
            this.Controls.Add(this.defPOSBox);
            this.Controls.Add(this.defHeadBox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "DefinitionForm";
            this.Text = "Definition Form";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox defHeadBox;
        private System.Windows.Forms.ComboBox defPOSBox;
        private System.Windows.Forms.Button addIllBtn;
        private System.Windows.Forms.TextBox defSDefBox;
        private System.Windows.Forms.TextBox defDefBox;
        private System.Windows.Forms.Button okBtn;
        private System.Windows.Forms.Button cnclBtn;
    }
}