/*********
*
* This file is part of BibleTime's source code, http://www.bibletime.info/.
*
* Copyright 1999-2011 by the BibleTime developers.
* The BibleTime source code is licensed under the GNU General Public License version 2.0.
*
**********/

#ifndef CFONTCHOOSER_H
#define CFONTCHOOSER_H

#include <QFrame>

#include <QWidget>


class QLabel;
class CListWidget;
class QListWidget;
class QListWidgetItem;
class QString;
class QWebView;

class BtFontChooserWidget : public QFrame {

        Q_OBJECT

    public: /* Methods: */

        BtFontChooserWidget(QWidget *parent = 0);

        void setFont(const QFont &font);
        void setSampleText(const QString &text);

        // Inherited from QWidget:
        virtual QSize sizeHint() const;

    signals:

        void fontSelected(const QFont&);

    private: /* Methods: */

        void createLayout();
        void retranslateUi();
        void connectListWidgets();
        QString formatAsHtml(const QString& text);
        void loadFonts();
        void loadSizes(const QString& font, const QString& style);
        void loadStyles(const QString& font);
        void outputHtmlText();
        void restoreListWidgetValue(QListWidget* listWidget, const QString& value);
        QString saveListWidgetValue(QListWidget* listWidget);


    private slots:

        void fontChanged(QListWidgetItem* current, QListWidgetItem* previous);
        void setFontStyle(const QString& styleString, QFont* font);
        void sizeChanged(QListWidgetItem* current, QListWidgetItem* previous);
        void styleChanged(QListWidgetItem* current, QListWidgetItem* previous);

    private: /* Fields: */

        QLabel *m_fontNameLabel;
            CListWidget *m_fontListWidget;
        QLabel *m_fontStyleLabel;
            CListWidget *m_styleListWidget;
        QLabel *m_fontSizeLabel;
            CListWidget *m_sizeListWidget;

        QWebView *m_fontPreview;

        QString m_htmlText;
        QFont m_font;
        QString m_choosenStyle;

};

#endif