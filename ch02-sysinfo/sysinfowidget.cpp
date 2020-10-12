#include "sysinfowidget.h"
#include <QVBoxLayout>

using namespace QtCharts;

SysInfoWidget::SysInfoWidget(QWidget *parent, int start_delay_ms, int update_series_delay_ms)
    : QWidget(parent),
      m_chart_view(this)
{
    m_refresh_timer.setInterval(update_series_delay_ms);

    connect(&m_refresh_timer, &QTimer::timeout,
            this, &SysInfoWidget::update_series);

    QTimer::singleShot(
                start_delay_ms,
                [this] {
        m_refresh_timer.start();
    });

    m_chart_view.setRenderHint(QPainter::Antialiasing);
    m_chart_view.chart()->legend()->setVisible(false);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(&m_chart_view);
    setLayout(layout);
}

QChartView &SysInfoWidget::chart_view()
{
    return m_chart_view;
}
