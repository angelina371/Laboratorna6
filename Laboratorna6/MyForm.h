#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;
#pragma once

namespace StudentStipendiaApp {

    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    ref struct Student
    {
        String^ FIO;
        int Kurs;
        String^ Group;
        double Stipendia;
    };

    public ref class MyForm : public Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
                delete components;
        }

    private:
        TextBox^ txtFIO;
        TextBox^ txtKurs;
        TextBox^ txtGroup;
        TextBox^ txtStipendia;
        Button^ btnAdd;
        ListBox^ listAllStudents;
        ListBox^ listNoStipend;

        System::ComponentModel::Container^ components;
        List<Student^>^ students = gcnew List<Student^>();

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->txtFIO = gcnew TextBox();
            this->txtKurs = gcnew TextBox();
            this->txtGroup = gcnew TextBox();
            this->txtStipendia = gcnew TextBox();
            this->btnAdd = gcnew Button();
            this->listAllStudents = gcnew ListBox();
            this->listNoStipend = gcnew ListBox();

            this->SuspendLayout();

           
            Label^ lblFIO = gcnew Label();
            lblFIO->Text = "ПІБ студента:";
            lblFIO->Location = Point(20, 0);
            lblFIO->Size = Drawing::Size(100, 20);
            this->Controls->Add(lblFIO);

            
            this->txtFIO->Location = Point(20, 20);
            this->txtFIO->Size = Drawing::Size(200, 22);

        
            Label^ lblKurs = gcnew Label();
            lblKurs->Text = "Курс:";
            lblKurs->Location = Point(20, 45);
            lblKurs->Size = Drawing::Size(50, 20);
            this->Controls->Add(lblKurs);

            this->txtKurs->Location = Point(70, 45);
            this->txtKurs->Size = Drawing::Size(50, 22);

          
            Label^ lblGroup = gcnew Label();
            lblGroup->Text = "Група:";
            lblGroup->Location = Point(20, 75);
            lblGroup->Size = Drawing::Size(50, 20);
            this->Controls->Add(lblGroup);

            this->txtGroup->Location = Point(70, 75);
            this->txtGroup->Size = Drawing::Size(100, 22);

           
            Label^ lblStipendia = gcnew Label();
            lblStipendia->Text = "Стипендія:";
            lblStipendia->Location = Point(20, 105);
            lblStipendia->Size = Drawing::Size(70, 20);
            this->Controls->Add(lblStipendia);

           
            this->txtStipendia->Location = Point(100, 105);
            this->txtStipendia->Size = Drawing::Size(70, 22);

          
            this->btnAdd->Location = Point(20, 150);
            this->btnAdd->Size = Drawing::Size(120, 30);
            this->btnAdd->Text = "Додати студента";
            this->btnAdd->Click += gcnew EventHandler(this, &MyForm::btnAdd_Click);

         
            this->listAllStudents->Location = Point(250, 20);
            this->listAllStudents->Size = Drawing::Size(300, 200);

            this->listNoStipend->Location = Point(580, 20);
            this->listNoStipend->Size = Drawing::Size(300, 200);

         
            this->ClientSize = Drawing::Size(900, 250);
            this->Controls->Add(this->txtFIO);
            this->Controls->Add(this->txtKurs);
            this->Controls->Add(this->txtGroup);
            this->Controls->Add(this->txtStipendia);
            this->Controls->Add(this->btnAdd);
            this->Controls->Add(this->listAllStudents);
            this->Controls->Add(this->listNoStipend);
            this->Text = "Обробка студентів";

            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        void btnAdd_Click(Object^ sender, EventArgs^ e)
        {
            try
            {
                Student^ st = gcnew Student();
                st->FIO = txtFIO->Text;
                st->Kurs = Convert::ToInt32(txtKurs->Text);
                st->Group = txtGroup->Text;
                st->Stipendia = Convert::ToDouble(txtStipendia->Text);

                students->Add(st);

                listAllStudents->Items->Add(
                    String::Format("{0}, Курс: {1}, Група: {2}, Стипендія: {3}",
                        st->FIO, st->Kurs, st->Group, st->Stipendia));

                if (st->Stipendia == 0)
                {
                    listNoStipend->Items->Add(
                        String::Format("{0}, Курс: {1}, Група: {2}",
                            st->FIO, st->Kurs, st->Group));
                }

                txtFIO->Clear();
                txtKurs->Clear();
                txtGroup->Clear();
                txtStipendia->Clear();
            }
            catch (FormatException^)
            {
                MessageBox::Show("Будь ласка, введіть правильні дані для курсу та стипендії.", "Помилка вводу");
            }
        }
    };
}