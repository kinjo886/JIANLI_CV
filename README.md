# 个人开源作品集

> 一个持续维护的开源项目集合，覆盖**政务数据工程与治理、机器学习算法从零实现、数据分析与统计推断、系统 / 工具链开发、C++ 游戏开发**等方向。本仓库为公开作品集首页，**不含任何个人真实信息**。

![License](https://img.shields.io/badge/license-MIT-green)
![Projects](https://img.shields.io/badge/projects-20-blue)
![Open](https://img.shields.io/badge/status-活跃-orange)

在线首页：https://kinjo886.github.io/JIANLI_CV/

---

## 技术方向

- **政务数据工程与治理**：数据迁移 / 字段映射 / 数源参数治理 / 数据共享清单审核 / MCP 工具链
- **机器学习算法从零实现**：KNN、手写数字识别（PyTorch）、多源特征融合检索（MATLAB）
- **数据分析与统计推断**：孟德尔随机化因果推断与稳健性检验（R）
- **系统 / 工具链开发**：技能管理平台、浏览器扩展、Electron 桌面应用、自动化脚本
- **C++ 游戏开发**：基于 EasyX / 原生 C++ 的趣味小游戏

---

## 项目总览

### 政务数据工程

| 项目 | 简介 | 技术栈 |
|------|------|--------|
| [skill-hub](https://github.com/kinjo886/skill-hub) | 轻量级技能管理 Web 平台：JWT 鉴权、技能上传审核、协作、排行榜 | JavaScript · Node.js + Express + sql.js |
| [data-migration-workbench](https://github.com/kinjo886/data-migration-workbench) | 政务数据迁移工作台：对接大数据治理平台，表结构解析、字段映射、批量迁移 | HTML · Node.js + 原生前端 |
| [longshu-param-tool](https://github.com/kinjo886/longshu-param-tool) | 浏览器扩展：一键提取网页表格并生成标准化作业入参，提升数据录入效率 | JavaScript |
| [excel-to-json-array](https://github.com/kinjo886/excel-to-json-array) | Python 小工具：将 Excel 多行多列表格转换为二维 JSON 数组，用于批量数据导入 | Python |
| [gov-platform-connectors](https://github.com/kinjo886/gov-platform-connectors) | MCP 工具：封装 DataArts Studio 与金山政务云两个 MCP Server | JavaScript |
| [data-sharing-list-review](https://github.com/kinjo886/data-sharing-list-review) | 数据共享清单智能审核技能包：SKILL.md + 5 阶段脚本 + 设计文档 | Python |
| [sql-field-validator](https://github.com/kinjo886/sql-field-validator) | SQL 字段核查与数据质量校验工具 | Python |
| [skill-warehouse-desktop](https://github.com/kinjo886/skill-warehouse-desktop) | 政务技能仓 1.0 桌面应用（Electron 源码） | HTML · Electron |
| [data-integration-toolchain](https://github.com/kinjo886/data-integration-toolchain) | 数据集成作业自动化工具链：二维数组工具 + 数源参数中间层 + CDM 作业 / 开发任务脚本 + 金山入库脚本 | Python |

### 机器学习与数据分析

| 项目 | 简介 | 技术栈 |
|------|------|--------|
| [knn-classifier](https://github.com/kinjo886/knn-classifier) | 从零实现的 K 近邻算法，含约会数据集示例 | Python · NumPy |
| [mnist-handwritten-recognizer](https://github.com/kinjo886/mnist-handwritten-recognizer) | 手写数字识别系统：画板手写、实时预测、含预训练权重 | Python · PyTorch + PySide6 |
| [multi-source-feature-fusion](https://github.com/kinjo886/multi-source-feature-fusion) | 多源特征融合图像检索系统：融合颜色 / 纹理 / 形状特征实现 CBIR，含样例数据集 | MATLAB |
| [apob-knee-oa-mendelian-randomization](https://github.com/kinjo886/apob-knee-oa-mendelian-randomization) | 载脂蛋白 B 与膝关节炎双向孟德尔随机化分析：两样本因果推断、质量控制与稳健性检验 | R |

### 课程与系统

| 项目 | 简介 | 技术栈 |
|------|------|--------|
| [edu_ai_exam_system](https://github.com/kinjo886/edu_ai_exam_system) | 基于 Qt6 + C++ 的智能出题与考试系统（课程设计） | C++ · Qt6 |

### 游戏与趣味

| 项目 | 简介 | 技术栈 |
|------|------|--------|
| [Cpp-Plants-Vs-Zombies](https://github.com/kinjo886/Cpp-Plants-Vs-Zombies) | 基于 C++ 和 EasyX 高度还原的《植物大战僵尸》复刻版 | C++ · EasyX |
| [Cpp-Teyvat-Survivors](https://github.com/kinjo886/Cpp-Teyvat-Survivors) | 原神风 Survivors 类小游戏 | C++ |
| [Cpp-TicTacToe](https://github.com/kinjo886/Cpp-TicTacToe) | 井字棋小游戏 | C++ |
| [Cpp-PlaneWar-Game](https://github.com/kinjo886/Cpp-PlaneWar-Game) | 飞机大战小游戏 | C++ |
| [Linux-Monitor-Tool](https://github.com/kinjo886/Linux-Monitor-Tool) | 轻量级 Linux 系统资源与进程状态监控脚本 | Shell |
| [Python-Job-Spider](https://github.com/kinjo886/Python-Job-Spider) | 招聘信息爬虫（课程练习） | Python |

---

## 仓库结构

| 文件 | 说明 |
|------|------|
| `index.html` | 作品集主页：全部开源项目卡片（按方向分组），不含个人真实信息 |
| `LICENSE` | MIT License |

> 说明：完整个人简历**不在此公开仓库中**。如需进一步了解，请通过 GitHub 私信联系。

## 本地预览

```bash
git clone https://github.com/kinjo886/JIANLI_CV.git
# 直接用浏览器打开 index.html 即可
```

## 隐私说明

本仓库为**公开脱敏版**：已移除证件照、真实姓名、联系方式、学校等所有可识别个人信息，仅保留项目与技术方向展示。如你对其中任何项目感兴趣，欢迎在 GitHub 上交流。

## 许可

本项目基于 [MIT License](./LICENSE) 开源。
