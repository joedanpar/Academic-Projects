namespace DictionaryEdit
{
    partial class IllustrationForm
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
            this.illDefBox = new System.Windows.Forms.TextBox();
            this.illIllBox = new System.Windows.Forms.TextBox();
            this.illTransBox = new System.Windows.Forms.TextBox();
            this.okIllBtn = new System.Windows.Forms.Button();
            this.cnclIllBtn = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(51, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Definition";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(13, 70);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(152, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Illustration (Example Sentence)";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(13, 133);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(59, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Translation";
            // 
            // illDefBox
            // 
            this.illDefBox.Location = new System.Drawing.Point(171, 13);
            this.illDefBox.Multiline = true;
            this.illDefBox.Name = "illDefBox";
            this.illDefBox.ReadOnly = true;
            this.illDefBox.Size = new System.Drawing.Size(503, 42);
            this.illDefBox.TabIndex = 3;
            // 
            // illIllBox
            // 
            this.illIllBox.Location = new System.Drawing.Point(171, 70);
            this.illIllBox.Multiline = true;
            this.illIllBox.Name = "illIllBox";
            this.illIllBox.Size = new System.Drawing.Size(503, 45);
            this.illIllBox.TabIndex = 4;
            // 
            // illTransBox
            // 
            this.illTransBox.Location = new System.Drawing.Point(171, 133);
            this.illTransBox.Multiline = true;
            this.illTransBox.Name = "illTransBox";
            this.illTransBox.Size = new System.Drawing.Size(503, 77);
            this.illTransBox.TabIndex = 5;
            // 
            // okIllBtn
            // 
            this.okIllBtn.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.okIllBtn.Location = new System.Drawing.Point(249, 227);
            this.okIllBtn.Name = "okIllBtn";
            this.okIllBtn.Size = new System.Drawing.Size(75, 23);
            this.okIllBtn.TabIndex = 6;
            this.okIllBtn.Text = "OK";
            this.okIllBtn.UseVisualStyleBackColor = true;
            this.okIllBtn.Click += new System.EventHandler(this.okIllBtn_Click);
            // 
            // cnclIllBtn
            // 
            this.cnclIllBtn.Location = new System.Drawing.Point(370, 227);
            this.cnclIllBtn.Name = "cnclIllBtn";
            this.cnclIllBtn.Size = new System.Drawing.Size(75, 23);
            this.cnclIllBtn.TabIndex = 7;
            this.cnclIllBtn.Text = "Cancel";
            this.cnclIllBtn.UseVisualStyleBackColor = true;
            this.cnclIllBtn.Click += new System.EventHandler(this.cnclIllBtn_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(13, 87);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(124, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "1 example sentence only";
            // 
            // IllustrationForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(689, 273);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.cnclIllBtn);
            this.Controls.Add(this.okIllBtn);
            this.Controls.Add(this.illTransBox);
            this.Controls.Add(this.illIllBox);
            this.Controls.Add(this.illDefBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "IllustrationForm";
            this.Text = "Illustration Form";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button okIllBtn;
        private System.Windows.Forms.Button cnclIllBtn;
        private System.Windows.Forms.Label label4;
        public System.Windows.Forms.TextBox illDefBox;
        public System.Windows.Forms.TextBox illIllBox;
        public System.Windows.Forms.TextBox illTransBox;
    }
}