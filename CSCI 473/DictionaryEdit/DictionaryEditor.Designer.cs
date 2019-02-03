namespace DictionaryEdit
{
    partial class DictionaryEditor
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
            this.headField = new System.Windows.Forms.TextBox();
            this.posField = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.pronField = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.semanBox = new System.Windows.Forms.ListBox();
            this.label6 = new System.Windows.Forms.Label();
            this.socialBox = new System.Windows.Forms.ListBox();
            this.label7 = new System.Windows.Forms.Label();
            this.checkBtn = new System.Windows.Forms.Button();
            this.adefBtn = new System.Windows.Forms.Button();
            this.addBtn = new System.Windows.Forms.Button();
            this.searchBtn = new System.Windows.Forms.Button();
            this.clearBtn = new System.Windows.Forms.Button();
            this.allBtn = new System.Windows.Forms.Button();
            this.exitBtn = new System.Windows.Forms.Button();
            this.clockLabel = new System.Windows.Forms.Label();
            this.turnBt = new System.Windows.Forms.Button();
            this.refBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // headField
            // 
            this.headField.Location = new System.Drawing.Point(147, 69);
            this.headField.Name = "headField";
            this.headField.Size = new System.Drawing.Size(174, 20);
            this.headField.TabIndex = 1;
            // 
            // posField
            // 
            this.posField.FormattingEnabled = true;
            this.posField.Items.AddRange(new object[] {
            "adj.",
            "adv.",
            "conj.",
            "ideo.",
            "prep.",
            "pro.",
            "n.",
            "v."});
            this.posField.Location = new System.Drawing.Point(147, 95);
            this.posField.Name = "posField";
            this.posField.Size = new System.Drawing.Size(174, 21);
            this.posField.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(59, 72);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(56, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Headword";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(59, 98);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(29, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "POS";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(59, 126);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(72, 13);
            this.label4.TabIndex = 5;
            this.label4.Text = "Pronunciation";
            // 
            // pronField
            // 
            this.pronField.Location = new System.Drawing.Point(147, 123);
            this.pronField.Name = "pronField";
            this.pronField.Size = new System.Drawing.Size(174, 20);
            this.pronField.TabIndex = 6;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(59, 177);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(81, 13);
            this.label5.TabIndex = 7;
            this.label5.Text = "Semantic Fields";
            // 
            // semanBox
            // 
            this.semanBox.FormattingEnabled = true;
            this.semanBox.Location = new System.Drawing.Point(147, 177);
            this.semanBox.Name = "semanBox";
            this.semanBox.SelectionMode = System.Windows.Forms.SelectionMode.MultiSimple;
            this.semanBox.Size = new System.Drawing.Size(174, 95);
            this.semanBox.TabIndex = 8;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(327, 177);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(70, 13);
            this.label6.TabIndex = 9;
            this.label6.Text = "Social Usage";
            // 
            // socialBox
            // 
            this.socialBox.FormattingEnabled = true;
            this.socialBox.Location = new System.Drawing.Point(403, 177);
            this.socialBox.Name = "socialBox";
            this.socialBox.SelectionMode = System.Windows.Forms.SelectionMode.MultiSimple;
            this.socialBox.Size = new System.Drawing.Size(174, 95);
            this.socialBox.TabIndex = 10;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(52, 312);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(91, 13);
            this.label7.TabIndex = 12;
            this.label7.Text = "Cross References";
            // 
            // checkBtn
            // 
            this.checkBtn.Location = new System.Drawing.Point(367, 69);
            this.checkBtn.Name = "checkBtn";
            this.checkBtn.Size = new System.Drawing.Size(87, 23);
            this.checkBtn.TabIndex = 13;
            this.checkBtn.Text = "Spell Check";
            this.checkBtn.UseVisualStyleBackColor = true;
            this.checkBtn.Click += new System.EventHandler(this.checkBtn_Click);
            // 
            // adefBtn
            // 
            this.adefBtn.Location = new System.Drawing.Point(367, 95);
            this.adefBtn.Name = "adefBtn";
            this.adefBtn.Size = new System.Drawing.Size(87, 23);
            this.adefBtn.TabIndex = 14;
            this.adefBtn.Text = "Add Definition";
            this.adefBtn.UseVisualStyleBackColor = true;
            this.adefBtn.Click += new System.EventHandler(this.adefBtn_Click);
            // 
            // addBtn
            // 
            this.addBtn.Location = new System.Drawing.Point(138, 427);
            this.addBtn.Name = "addBtn";
            this.addBtn.Size = new System.Drawing.Size(75, 23);
            this.addBtn.TabIndex = 15;
            this.addBtn.Text = "Add Entry";
            this.addBtn.UseVisualStyleBackColor = true;
            this.addBtn.Click += new System.EventHandler(this.addBtn_Click);
            // 
            // searchBtn
            // 
            this.searchBtn.Location = new System.Drawing.Point(234, 427);
            this.searchBtn.Name = "searchBtn";
            this.searchBtn.Size = new System.Drawing.Size(75, 23);
            this.searchBtn.TabIndex = 16;
            this.searchBtn.Text = "Search/Edit";
            this.searchBtn.UseVisualStyleBackColor = true;
            // 
            // clearBtn
            // 
            this.clearBtn.Location = new System.Drawing.Point(330, 427);
            this.clearBtn.Name = "clearBtn";
            this.clearBtn.Size = new System.Drawing.Size(75, 23);
            this.clearBtn.TabIndex = 17;
            this.clearBtn.Text = "Clear";
            this.clearBtn.UseVisualStyleBackColor = true;
            this.clearBtn.Click += new System.EventHandler(this.clearBtn_Click);
            // 
            // allBtn
            // 
            this.allBtn.Location = new System.Drawing.Point(423, 427);
            this.allBtn.Name = "allBtn";
            this.allBtn.Size = new System.Drawing.Size(87, 23);
            this.allBtn.TabIndex = 18;
            this.allBtn.Text = "See All Words";
            this.allBtn.UseVisualStyleBackColor = true;
            // 
            // exitBtn
            // 
            this.exitBtn.Location = new System.Drawing.Point(531, 427);
            this.exitBtn.Name = "exitBtn";
            this.exitBtn.Size = new System.Drawing.Size(75, 23);
            this.exitBtn.TabIndex = 19;
            this.exitBtn.Text = "Exit";
            this.exitBtn.UseVisualStyleBackColor = true;
            this.exitBtn.Click += new System.EventHandler(this.exitBtn_Click);
            // 
            // clockLabel
            // 
            this.clockLabel.AutoSize = true;
            this.clockLabel.Location = new System.Drawing.Point(635, 19);
            this.clockLabel.Name = "clockLabel";
            this.clockLabel.Size = new System.Drawing.Size(34, 13);
            this.clockLabel.TabIndex = 20;
            this.clockLabel.Text = "Clock";
            // 
            // turnBt
            // 
            this.turnBt.Location = new System.Drawing.Point(475, 69);
            this.turnBt.Name = "turnBt";
            this.turnBt.Size = new System.Drawing.Size(89, 23);
            this.turnBt.TabIndex = 21;
            this.turnBt.Text = "Turn Words On";
            this.turnBt.UseVisualStyleBackColor = true;
            this.turnBt.Click += new System.EventHandler(this.turnBt_Click);
            // 
            // refBox
            // 
            this.refBox.Location = new System.Drawing.Point(147, 309);
            this.refBox.Multiline = true;
            this.refBox.Name = "refBox";
            this.refBox.Size = new System.Drawing.Size(430, 101);
            this.refBox.TabIndex = 22;
            // 
            // DictionaryEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(698, 527);
            this.Controls.Add(this.refBox);
            this.Controls.Add(this.turnBt);
            this.Controls.Add(this.clockLabel);
            this.Controls.Add(this.exitBtn);
            this.Controls.Add(this.allBtn);
            this.Controls.Add(this.clearBtn);
            this.Controls.Add(this.searchBtn);
            this.Controls.Add(this.addBtn);
            this.Controls.Add(this.adefBtn);
            this.Controls.Add(this.checkBtn);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.socialBox);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.semanBox);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.pronField);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.posField);
            this.Controls.Add(this.headField);
            this.Name = "DictionaryEditor";
            this.Text = "Dictionary Editor";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox headField;
        private System.Windows.Forms.ComboBox posField;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox pronField;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ListBox semanBox;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ListBox socialBox;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button checkBtn;
        private System.Windows.Forms.Button adefBtn;
        private System.Windows.Forms.Button addBtn;
        private System.Windows.Forms.Button searchBtn;
        private System.Windows.Forms.Button clearBtn;
        private System.Windows.Forms.Button allBtn;
        private System.Windows.Forms.Button exitBtn;
        private System.Windows.Forms.Label clockLabel;
        private System.Windows.Forms.Button turnBt;
        private System.Windows.Forms.TextBox refBox;
    }
}

