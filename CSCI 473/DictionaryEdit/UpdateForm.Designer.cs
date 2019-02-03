namespace DictionaryEdit
{
    partial class UpdateForm
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
            this.tabControl = new System.Windows.Forms.TabControl();
            this.mainTab = new System.Windows.Forms.TabPage();
            this.concurBox = new System.Windows.Forms.CheckBox();
            this.mCloseBtn = new System.Windows.Forms.Button();
            this.mDeleteBtn = new System.Windows.Forms.Button();
            this.mUpdateBtn = new System.Windows.Forms.Button();
            this.mSocialBox = new System.Windows.Forms.ListBox();
            this.label6 = new System.Windows.Forms.Label();
            this.mSemanBox = new System.Windows.Forms.ListBox();
            this.label5 = new System.Windows.Forms.Label();
            this.mPOSBox = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.mHeadField = new System.Windows.Forms.TextBox();
            this.mPronField = new System.Windows.Forms.TextBox();
            this.mRefField = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.defTab = new System.Windows.Forms.TabPage();
            this.dUpdateBtn = new System.Windows.Forms.Button();
            this.dReorderBtn = new System.Windows.Forms.Button();
            this.dAddBtn = new System.Windows.Forms.Button();
            this.dClearBtn = new System.Windows.Forms.Button();
            this.dDeleteBtn = new System.Windows.Forms.Button();
            this.dDefField = new System.Windows.Forms.TextBox();
            this.dShortDef = new System.Windows.Forms.TextBox();
            this.numBox = new System.Windows.Forms.ComboBox();
            this.dPOSBox = new System.Windows.Forms.ComboBox();
            this.label12 = new System.Windows.Forms.Label();
            this.numLabel = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.dHeadField = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.illTab = new System.Windows.Forms.TabPage();
            this.iDeleteBtn = new System.Windows.Forms.Button();
            this.iAddBtn = new System.Windows.Forms.Button();
            this.iClearBtn = new System.Windows.Forms.Button();
            this.iUpdateBtn = new System.Windows.Forms.Button();
            this.iNumbox = new System.Windows.Forms.ComboBox();
            this.iTransField = new System.Windows.Forms.TextBox();
            this.iIllField = new System.Windows.Forms.TextBox();
            this.label17 = new System.Windows.Forms.Label();
            this.iDefNum = new System.Windows.Forms.TextBox();
            this.iHeadField = new System.Windows.Forms.TextBox();
            this.label16 = new System.Windows.Forms.Label();
            this.iNumLabel = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.tabControl.SuspendLayout();
            this.mainTab.SuspendLayout();
            this.defTab.SuspendLayout();
            this.illTab.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl
            // 
            this.tabControl.Controls.Add(this.mainTab);
            this.tabControl.Controls.Add(this.defTab);
            this.tabControl.Controls.Add(this.illTab);
            this.tabControl.Location = new System.Drawing.Point(2, 3);
            this.tabControl.Name = "tabControl";
            this.tabControl.SelectedIndex = 0;
            this.tabControl.Size = new System.Drawing.Size(667, 386);
            this.tabControl.TabIndex = 0;
            this.tabControl.SelectedIndexChanged += new System.EventHandler(this.tabControl_SelectedIndexChanged);
            // 
            // mainTab
            // 
            this.mainTab.Controls.Add(this.concurBox);
            this.mainTab.Controls.Add(this.mCloseBtn);
            this.mainTab.Controls.Add(this.mDeleteBtn);
            this.mainTab.Controls.Add(this.mUpdateBtn);
            this.mainTab.Controls.Add(this.mSocialBox);
            this.mainTab.Controls.Add(this.label6);
            this.mainTab.Controls.Add(this.mSemanBox);
            this.mainTab.Controls.Add(this.label5);
            this.mainTab.Controls.Add(this.mPOSBox);
            this.mainTab.Controls.Add(this.label4);
            this.mainTab.Controls.Add(this.mHeadField);
            this.mainTab.Controls.Add(this.mPronField);
            this.mainTab.Controls.Add(this.mRefField);
            this.mainTab.Controls.Add(this.label3);
            this.mainTab.Controls.Add(this.label2);
            this.mainTab.Controls.Add(this.label1);
            this.mainTab.Location = new System.Drawing.Point(4, 22);
            this.mainTab.Name = "mainTab";
            this.mainTab.Padding = new System.Windows.Forms.Padding(3);
            this.mainTab.Size = new System.Drawing.Size(659, 360);
            this.mainTab.TabIndex = 0;
            this.mainTab.Text = "Main Info";
            this.mainTab.UseVisualStyleBackColor = true;
            // 
            // concurBox
            // 
            this.concurBox.AutoSize = true;
            this.concurBox.Location = new System.Drawing.Point(129, 279);
            this.concurBox.Name = "concurBox";
            this.concurBox.Size = new System.Drawing.Size(129, 17);
            this.concurBox.TabIndex = 15;
            this.concurBox.Text = "Simulate Concurrency";
            this.concurBox.UseVisualStyleBackColor = true;
            // 
            // mCloseBtn
            // 
            this.mCloseBtn.Location = new System.Drawing.Point(330, 248);
            this.mCloseBtn.Name = "mCloseBtn";
            this.mCloseBtn.Size = new System.Drawing.Size(103, 23);
            this.mCloseBtn.TabIndex = 14;
            this.mCloseBtn.Text = "Close this Window";
            this.mCloseBtn.UseVisualStyleBackColor = true;
            this.mCloseBtn.Click += new System.EventHandler(this.mCloseBtn_Click);
            // 
            // mDeleteBtn
            // 
            this.mDeleteBtn.Location = new System.Drawing.Point(232, 248);
            this.mDeleteBtn.Name = "mDeleteBtn";
            this.mDeleteBtn.Size = new System.Drawing.Size(92, 23);
            this.mDeleteBtn.TabIndex = 13;
            this.mDeleteBtn.Text = "Delete this Entry";
            this.mDeleteBtn.UseVisualStyleBackColor = true;
            this.mDeleteBtn.Click += new System.EventHandler(this.mDeleteBtn_Click);
            // 
            // mUpdateBtn
            // 
            this.mUpdateBtn.Location = new System.Drawing.Point(129, 249);
            this.mUpdateBtn.Name = "mUpdateBtn";
            this.mUpdateBtn.Size = new System.Drawing.Size(96, 23);
            this.mUpdateBtn.TabIndex = 12;
            this.mUpdateBtn.Text = "Update this Entry";
            this.mUpdateBtn.UseVisualStyleBackColor = true;
            this.mUpdateBtn.Click += new System.EventHandler(this.mUpdateBtn_Click);
            // 
            // mSocialBox
            // 
            this.mSocialBox.FormattingEnabled = true;
            this.mSocialBox.Location = new System.Drawing.Point(495, 178);
            this.mSocialBox.Name = "mSocialBox";
            this.mSocialBox.Size = new System.Drawing.Size(151, 95);
            this.mSocialBox.TabIndex = 11;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(411, 178);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(70, 13);
            this.label6.TabIndex = 10;
            this.label6.Text = "Social Usage";
            // 
            // mSemanBox
            // 
            this.mSemanBox.FormattingEnabled = true;
            this.mSemanBox.Location = new System.Drawing.Point(495, 71);
            this.mSemanBox.Name = "mSemanBox";
            this.mSemanBox.Size = new System.Drawing.Size(151, 95);
            this.mSemanBox.TabIndex = 9;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(408, 74);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(81, 13);
            this.label5.TabIndex = 8;
            this.label5.Text = "Semantic Fields";
            // 
            // mPOSBox
            // 
            this.mPOSBox.FormattingEnabled = true;
            this.mPOSBox.Items.AddRange(new object[] {
            "adj.",
            "adv.",
            "conj.",
            "ideo.",
            "prep.",
            "pro.",
            "n.",
            "v."});
            this.mPOSBox.Location = new System.Drawing.Point(381, 13);
            this.mPOSBox.Name = "mPOSBox";
            this.mPOSBox.Size = new System.Drawing.Size(167, 21);
            this.mPOSBox.TabIndex = 7;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(337, 16);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(29, 13);
            this.label4.TabIndex = 6;
            this.label4.Text = "POS";
            // 
            // mHeadField
            // 
            this.mHeadField.Location = new System.Drawing.Point(129, 13);
            this.mHeadField.Name = "mHeadField";
            this.mHeadField.ReadOnly = true;
            this.mHeadField.Size = new System.Drawing.Size(175, 20);
            this.mHeadField.TabIndex = 5;
            // 
            // mPronField
            // 
            this.mPronField.Location = new System.Drawing.Point(129, 43);
            this.mPronField.Name = "mPronField";
            this.mPronField.Size = new System.Drawing.Size(175, 20);
            this.mPronField.TabIndex = 4;
            // 
            // mRefField
            // 
            this.mRefField.Location = new System.Drawing.Point(129, 71);
            this.mRefField.Multiline = true;
            this.mRefField.Name = "mRefField";
            this.mRefField.Size = new System.Drawing.Size(256, 76);
            this.mRefField.TabIndex = 3;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(20, 74);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(91, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Cross References";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(20, 46);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(72, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Pronunciation";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(20, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(56, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Headword";
            // 
            // defTab
            // 
            this.defTab.Controls.Add(this.dUpdateBtn);
            this.defTab.Controls.Add(this.dReorderBtn);
            this.defTab.Controls.Add(this.dAddBtn);
            this.defTab.Controls.Add(this.dClearBtn);
            this.defTab.Controls.Add(this.dDeleteBtn);
            this.defTab.Controls.Add(this.dDefField);
            this.defTab.Controls.Add(this.dShortDef);
            this.defTab.Controls.Add(this.numBox);
            this.defTab.Controls.Add(this.dPOSBox);
            this.defTab.Controls.Add(this.label12);
            this.defTab.Controls.Add(this.numLabel);
            this.defTab.Controls.Add(this.label10);
            this.defTab.Controls.Add(this.label9);
            this.defTab.Controls.Add(this.dHeadField);
            this.defTab.Controls.Add(this.label8);
            this.defTab.Controls.Add(this.label7);
            this.defTab.Location = new System.Drawing.Point(4, 22);
            this.defTab.Name = "defTab";
            this.defTab.Padding = new System.Windows.Forms.Padding(3);
            this.defTab.Size = new System.Drawing.Size(659, 360);
            this.defTab.TabIndex = 1;
            this.defTab.Text = "Definitions";
            this.defTab.UseVisualStyleBackColor = true;
            // 
            // dUpdateBtn
            // 
            this.dUpdateBtn.Location = new System.Drawing.Point(339, 219);
            this.dUpdateBtn.Name = "dUpdateBtn";
            this.dUpdateBtn.Size = new System.Drawing.Size(119, 23);
            this.dUpdateBtn.TabIndex = 15;
            this.dUpdateBtn.Text = "Update this Definition";
            this.dUpdateBtn.UseVisualStyleBackColor = true;
            this.dUpdateBtn.Click += new System.EventHandler(this.dUpdateBtn_Click);
            // 
            // dReorderBtn
            // 
            this.dReorderBtn.Location = new System.Drawing.Point(464, 219);
            this.dReorderBtn.Name = "dReorderBtn";
            this.dReorderBtn.Size = new System.Drawing.Size(112, 23);
            this.dReorderBtn.TabIndex = 14;
            this.dReorderBtn.Text = "Reorder Definition";
            this.dReorderBtn.UseVisualStyleBackColor = true;
            this.dReorderBtn.Click += new System.EventHandler(this.dReorderBtn_Click);
            // 
            // dAddBtn
            // 
            this.dAddBtn.Enabled = false;
            this.dAddBtn.Location = new System.Drawing.Point(464, 251);
            this.dAddBtn.Name = "dAddBtn";
            this.dAddBtn.Size = new System.Drawing.Size(112, 23);
            this.dAddBtn.TabIndex = 13;
            this.dAddBtn.Text = "Add New Definition";
            this.dAddBtn.UseVisualStyleBackColor = true;
            this.dAddBtn.Click += new System.EventHandler(this.dAddBtn_Click);
            // 
            // dClearBtn
            // 
            this.dClearBtn.Location = new System.Drawing.Point(405, 251);
            this.dClearBtn.Name = "dClearBtn";
            this.dClearBtn.Size = new System.Drawing.Size(53, 23);
            this.dClearBtn.TabIndex = 12;
            this.dClearBtn.Text = "Clear";
            this.dClearBtn.UseVisualStyleBackColor = true;
            this.dClearBtn.Click += new System.EventHandler(this.dClearBtn_Click);
            // 
            // dDeleteBtn
            // 
            this.dDeleteBtn.Location = new System.Drawing.Point(275, 251);
            this.dDeleteBtn.Name = "dDeleteBtn";
            this.dDeleteBtn.Size = new System.Drawing.Size(124, 23);
            this.dDeleteBtn.TabIndex = 11;
            this.dDeleteBtn.Text = "Delete This Definition";
            this.dDeleteBtn.UseVisualStyleBackColor = true;
            this.dDeleteBtn.Click += new System.EventHandler(this.dDeleteBtn_Click);
            // 
            // dDefField
            // 
            this.dDefField.Location = new System.Drawing.Point(102, 117);
            this.dDefField.Multiline = true;
            this.dDefField.Name = "dDefField";
            this.dDefField.Size = new System.Drawing.Size(459, 87);
            this.dDefField.TabIndex = 10;
            // 
            // dShortDef
            // 
            this.dShortDef.Location = new System.Drawing.Point(102, 88);
            this.dShortDef.Name = "dShortDef";
            this.dShortDef.Size = new System.Drawing.Size(459, 20);
            this.dShortDef.TabIndex = 9;
            // 
            // numBox
            // 
            this.numBox.FormattingEnabled = true;
            this.numBox.Location = new System.Drawing.Point(182, 253);
            this.numBox.Name = "numBox";
            this.numBox.Size = new System.Drawing.Size(87, 21);
            this.numBox.TabIndex = 8;
            this.numBox.SelectedIndexChanged += new System.EventHandler(this.numBox_SelectedIndexChanged);
            // 
            // dPOSBox
            // 
            this.dPOSBox.FormattingEnabled = true;
            this.dPOSBox.Items.AddRange(new object[] {
            "adj.",
            "adv.",
            "conj.",
            "ideo.",
            "prep.",
            "pro.",
            "n.",
            "v."});
            this.dPOSBox.Location = new System.Drawing.Point(102, 39);
            this.dPOSBox.Name = "dPOSBox";
            this.dPOSBox.Size = new System.Drawing.Size(151, 21);
            this.dPOSBox.TabIndex = 7;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(17, 256);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(159, 13);
            this.label12.TabIndex = 6;
            this.label12.Text = "Choose which definition to view.";
            // 
            // numLabel
            // 
            this.numLabel.AutoSize = true;
            this.numLabel.Location = new System.Drawing.Point(17, 224);
            this.numLabel.Name = "numLabel";
            this.numLabel.Size = new System.Drawing.Size(19, 13);
            this.numLabel.TabIndex = 5;
            this.numLabel.Text = "***";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(17, 120);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(51, 13);
            this.label10.TabIndex = 4;
            this.label10.Text = "Definition";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(17, 91);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(79, 13);
            this.label9.TabIndex = 3;
            this.label9.Text = "Short Definition";
            // 
            // dHeadField
            // 
            this.dHeadField.Location = new System.Drawing.Point(102, 14);
            this.dHeadField.Name = "dHeadField";
            this.dHeadField.ReadOnly = true;
            this.dHeadField.Size = new System.Drawing.Size(151, 20);
            this.dHeadField.TabIndex = 2;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(17, 42);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(29, 13);
            this.label8.TabIndex = 1;
            this.label8.Text = "POS";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(17, 17);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(56, 13);
            this.label7.TabIndex = 0;
            this.label7.Text = "Headword";
            // 
            // illTab
            // 
            this.illTab.Controls.Add(this.iDeleteBtn);
            this.illTab.Controls.Add(this.iAddBtn);
            this.illTab.Controls.Add(this.iClearBtn);
            this.illTab.Controls.Add(this.iUpdateBtn);
            this.illTab.Controls.Add(this.iNumbox);
            this.illTab.Controls.Add(this.iTransField);
            this.illTab.Controls.Add(this.iIllField);
            this.illTab.Controls.Add(this.label17);
            this.illTab.Controls.Add(this.iDefNum);
            this.illTab.Controls.Add(this.iHeadField);
            this.illTab.Controls.Add(this.label16);
            this.illTab.Controls.Add(this.iNumLabel);
            this.illTab.Controls.Add(this.label14);
            this.illTab.Controls.Add(this.label13);
            this.illTab.Controls.Add(this.label11);
            this.illTab.Location = new System.Drawing.Point(4, 22);
            this.illTab.Name = "illTab";
            this.illTab.Size = new System.Drawing.Size(659, 360);
            this.illTab.TabIndex = 2;
            this.illTab.Text = "Illustations";
            this.illTab.UseVisualStyleBackColor = true;
            // 
            // iDeleteBtn
            // 
            this.iDeleteBtn.Location = new System.Drawing.Point(446, 291);
            this.iDeleteBtn.Name = "iDeleteBtn";
            this.iDeleteBtn.Size = new System.Drawing.Size(75, 23);
            this.iDeleteBtn.TabIndex = 14;
            this.iDeleteBtn.Text = "Delete this Illustration";
            this.iDeleteBtn.UseVisualStyleBackColor = true;
            this.iDeleteBtn.Click += new System.EventHandler(this.iDeleteBtn_Click);
            // 
            // iAddBtn
            // 
            this.iAddBtn.Enabled = false;
            this.iAddBtn.Location = new System.Drawing.Point(307, 291);
            this.iAddBtn.Name = "iAddBtn";
            this.iAddBtn.Size = new System.Drawing.Size(119, 23);
            this.iAddBtn.TabIndex = 13;
            this.iAddBtn.Text = "Add New Illustration";
            this.iAddBtn.UseVisualStyleBackColor = true;
            this.iAddBtn.Click += new System.EventHandler(this.iAddBtn_Click);
            // 
            // iClearBtn
            // 
            this.iClearBtn.Location = new System.Drawing.Point(200, 291);
            this.iClearBtn.Name = "iClearBtn";
            this.iClearBtn.Size = new System.Drawing.Size(75, 23);
            this.iClearBtn.TabIndex = 12;
            this.iClearBtn.Text = "Clear";
            this.iClearBtn.UseVisualStyleBackColor = true;
            this.iClearBtn.Click += new System.EventHandler(this.iClearBtn_Click);
            // 
            // iUpdateBtn
            // 
            this.iUpdateBtn.Location = new System.Drawing.Point(55, 291);
            this.iUpdateBtn.Name = "iUpdateBtn";
            this.iUpdateBtn.Size = new System.Drawing.Size(118, 23);
            this.iUpdateBtn.TabIndex = 11;
            this.iUpdateBtn.Text = "Update this Illustration";
            this.iUpdateBtn.UseVisualStyleBackColor = true;
            this.iUpdateBtn.Click += new System.EventHandler(this.iUpdateBtn_Click);
            // 
            // iNumbox
            // 
            this.iNumbox.FormattingEnabled = true;
            this.iNumbox.Location = new System.Drawing.Point(187, 245);
            this.iNumbox.Name = "iNumbox";
            this.iNumbox.Size = new System.Drawing.Size(71, 21);
            this.iNumbox.TabIndex = 10;
            this.iNumbox.SelectedIndexChanged += new System.EventHandler(this.iNumbox_SelectedIndexChanged);
            // 
            // iTransField
            // 
            this.iTransField.Location = new System.Drawing.Point(103, 141);
            this.iTransField.Multiline = true;
            this.iTransField.Name = "iTransField";
            this.iTransField.Size = new System.Drawing.Size(418, 69);
            this.iTransField.TabIndex = 9;
            // 
            // iIllField
            // 
            this.iIllField.Location = new System.Drawing.Point(103, 48);
            this.iIllField.Multiline = true;
            this.iIllField.Name = "iIllField";
            this.iIllField.Size = new System.Drawing.Size(418, 77);
            this.iIllField.TabIndex = 8;
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(326, 19);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(89, 13);
            this.label17.TabIndex = 7;
            this.label17.Text = "Defintion Number";
            // 
            // iDefNum
            // 
            this.iDefNum.Location = new System.Drawing.Point(421, 16);
            this.iDefNum.Name = "iDefNum";
            this.iDefNum.ReadOnly = true;
            this.iDefNum.Size = new System.Drawing.Size(100, 20);
            this.iDefNum.TabIndex = 6;
            // 
            // iHeadField
            // 
            this.iHeadField.Location = new System.Drawing.Point(103, 16);
            this.iHeadField.Name = "iHeadField";
            this.iHeadField.ReadOnly = true;
            this.iHeadField.Size = new System.Drawing.Size(187, 20);
            this.iHeadField.TabIndex = 5;
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(18, 248);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(163, 13);
            this.label16.TabIndex = 4;
            this.label16.Text = "Choose which illustration to view.";
            // 
            // iNumLabel
            // 
            this.iNumLabel.AutoSize = true;
            this.iNumLabel.Location = new System.Drawing.Point(18, 223);
            this.iNumLabel.Name = "iNumLabel";
            this.iNumLabel.Size = new System.Drawing.Size(19, 13);
            this.iNumLabel.TabIndex = 3;
            this.iNumLabel.Text = "***";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(18, 141);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(59, 13);
            this.label14.TabIndex = 2;
            this.label14.Text = "Translation";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(18, 51);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(54, 13);
            this.label13.TabIndex = 1;
            this.label13.Text = "Illustration";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(18, 19);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(56, 13);
            this.label11.TabIndex = 0;
            this.label11.Text = "Headword";
            // 
            // UpdateForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(671, 389);
            this.Controls.Add(this.tabControl);
            this.Name = "UpdateForm";
            this.Text = "UpdateForm";
            this.tabControl.ResumeLayout(false);
            this.mainTab.ResumeLayout(false);
            this.mainTab.PerformLayout();
            this.defTab.ResumeLayout(false);
            this.defTab.PerformLayout();
            this.illTab.ResumeLayout(false);
            this.illTab.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl;
        private System.Windows.Forms.TabPage mainTab;
        private System.Windows.Forms.TabPage defTab;
        private System.Windows.Forms.TabPage illTab;
        private System.Windows.Forms.TextBox mPronField;
        private System.Windows.Forms.TextBox mRefField;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox mHeadField;
        private System.Windows.Forms.CheckBox concurBox;
        private System.Windows.Forms.Button mCloseBtn;
        private System.Windows.Forms.Button mDeleteBtn;
        private System.Windows.Forms.Button mUpdateBtn;
        private System.Windows.Forms.ListBox mSocialBox;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ListBox mSemanBox;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox mPOSBox;
        private System.Windows.Forms.ComboBox dPOSBox;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label numLabel;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox dHeadField;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox dDefField;
        private System.Windows.Forms.TextBox dShortDef;
        private System.Windows.Forms.ComboBox numBox;
        private System.Windows.Forms.Button dClearBtn;
        private System.Windows.Forms.Button dDeleteBtn;
        private System.Windows.Forms.Button dUpdateBtn;
        private System.Windows.Forms.Button dReorderBtn;
        private System.Windows.Forms.Button dAddBtn;
        private System.Windows.Forms.TextBox iIllField;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.TextBox iDefNum;
        private System.Windows.Forms.TextBox iHeadField;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.Label iNumLabel;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox iTransField;
        private System.Windows.Forms.Button iDeleteBtn;
        private System.Windows.Forms.Button iAddBtn;
        private System.Windows.Forms.Button iClearBtn;
        private System.Windows.Forms.Button iUpdateBtn;
        private System.Windows.Forms.ComboBox iNumbox;
    }
}