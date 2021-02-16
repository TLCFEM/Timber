////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2021 Theodore Chang, Minghao Li
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////////////////////

#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include <Database.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE

namespace Ui {
    class ModelBuilder;
}

QT_END_NAMESPACE

class ModelBuilder final : public QMainWindow {
    Q_OBJECT
public:
    explicit ModelBuilder(QWidget* = nullptr);
    ~ModelBuilder() override;

public slots:
    void highlightNode(QString, int);
    void highlightNodeA(QString);
    void highlightNodeB(QString);
    void highlightNodeC(QString);
    void highlightNodeD(QString);
    void highlightNodeE();

    void highlightElement(QString, int);
    void highlightElementA(QString);

    void showAbout();
    void openFile();
    void writeOutput();

private slots:
    void on_box_analysis_type_currentIndexChanged(int);
    void on_box_element_currentTextChanged(const QString&);
    void on_box_element_type_currentTextChanged(const QString&);
    void on_box_frame_section_textHighlighted(const QString&);
    void on_box_load_type_currentTextChanged(const QString&);
    void on_box_modify_type_currentIndexChanged(int);
    void on_box_section_2_textHighlighted(const QString&);
    void on_box_section_textHighlighted(const QString&);
    void on_box_unit_currentIndexChanged(int);
    void on_box_wall_section_textHighlighted(const QString&);
    void on_button_add_bc_clicked();
    void on_button_add_element_clicked();
    void on_button_add_frame_section_clicked();
    void on_button_add_load_clicked();
    void on_button_add_node_clicked();
    void on_button_add_wall_section_clicked();
    void on_button_change_section_clicked();
    void on_button_clear_bc_clicked();
    void on_button_clear_load_clicked();
    void on_button_modify_node_clicked();
    void on_button_remove_all_element_clicked();
    void on_button_remove_element_clicked();
    void on_button_remove_frame_section_clicked();
    void on_button_remove_wall_section_clicked();
    void on_button_split_element_clicked();
    void on_input_absf_textChanged(const QString&);
    void on_input_absu_textChanged(const QString&);
    void on_input_absx_textChanged(const QString&);
    void on_input_damping_textChanged(const QString&);
    void on_input_frame_section_tag_textChanged(const QString&);
    void on_input_qfx_textChanged(const QString&);
    void on_input_qfy_textChanged(const QString&);
    void on_input_qfz_textChanged(const QString&);
    void on_input_qwx_textChanged(const QString&);
    void on_input_qwy_textChanged(const QString&);
    void on_input_relf_textChanged(const QString&);
    void on_input_relu_textChanged(const QString&);
    void on_input_relx_textChanged(const QString&);
    void on_input_scale_textChanged(const QString&);
    void on_input_wall_section_tag_textChanged(const QString&);
    void on_reset_model_clicked();

private:
    Ui::ModelBuilder* ui;
    Database model;

    QVector<int> highlighted_node = QVector<int>(4, 0);
    QVector<int> highlighted_group = QVector<int>();
    QVector<int> highlighted_element = QVector<int>(1, 0);

    void updateNodeList() const;
    void updateFrameSectionList() const;
    void updateWallSectionList() const;
    void updateElementList() const;

    void updateAnalysisSetting();
};
#endif // MODELBUILDER_H
