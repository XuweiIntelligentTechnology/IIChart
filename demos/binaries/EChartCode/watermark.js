/**
 * 自定义文字水印
 */
const watermark = function () {
    return {
        build: function(arg) {
            // 获取页面宽度
            let maxWidth = Math.max(document.body.scrollWidth, document.body.clientWidth) - 20;
            // 获取页面高度
            let maxHeight = Math.max(document.body.scrollHeight, document.body.clientHeight) + 0;
			console.info(maxWidth);
			console.info(maxHeight);
            if (maxHeight === 0){
                console.info("该页面无敏感内容~");
                return;
            }
            const setting = {
                text: "乐和彩科技（深圳）有限公司@Copyright",    // 默认水印内容
                beginX: 0,              // 默认起始x坐标
                endX: 0,                 // 默认结束x坐标
                beginY: 50,              // 默认起始y坐标
                endY: 0,                 // 默认结束y坐标
                intervalX: 50,          // 默认横向间隔宽度
                intervalY: 50,          // 默认纵向间隔高度
                opacity: 0.3,            // 字体透明度
                angle: 20,               // 字体倾斜度
                fontsize: '15px',        // 字体大小
                fontFamily: '微软雅黑',   // 字体
                width: 200,              // 水印（每个）宽度
                height: 80,              // 水印（每个）高度
                innerDate: false,        // 是否附带日期
            };
            // 默认变量与自定义变量结合
            if (arguments.length ===1 && typeof arguments[0] === "object"){
                const src = arguments[0] || {};
                for (const key in src){
                    if (!src.hasOwnProperty(key) || !src[key]){
                        continue;
                    }
                    for (const def in setting){
                        if (key === def){
                            setting[def] = src[key];
                        }
                    }
                }
            }
            // 计算列个数
            let cols = parseInt((maxWidth - setting.beginX - setting.endX) / (setting.width + setting.intervalX));
			if ((maxWidth - setting.beginX - setting.endX) - cols*(setting.width + setting.intervalX) >= setting.width)
			{
				cols = cols + 1;
			}
            // 计算行个数
            let rows = parseInt((maxHeight - setting.beginY - setting.endY) / (setting.height + setting.intervalY));
			if ((maxHeight - setting.beginY - setting.endY) - rows*(setting.height + setting.intervalY))
			{
				rows = rows + 1;
			}
			
			console.info(cols);
			console.info(rows);
			
            // 水印内容附加日期
            if (setting.innerDate){
                const date = new Date();
                setting.text = [setting.text, "<br>", date.getFullYear(), "年", date.getMonth() + 1, "月", date.getDate(), "日"].join("");
            }
            const fragment = document.createDocumentFragment();
            let x, y;
            for (let i=0; i<rows; i++){
                y = setting.beginY + (setting.intervalY + setting.height) * i;
                for (let j=0; j<cols; j++){
                    x = setting.beginX + (setting.width + setting.intervalX) * j;
                    const element = document.createElement('div');
                    element.id = 'watermark' + i + j;
                    // 设置倾斜角
                    element.style.MozTransform = "rotate(-" + setting.angle + "deg)";
                    element.style.msTransform = "rotate(-" + setting.angle + "deg)";
                    element.style.OTransform = "rotate(-" + setting.angle + "deg)";
                    element.style.transform = "rotate(-" + setting.angle + "deg)";
                    element.style.position = "absolute";
                    element.style.left = x + 'px';
                    element.style.top = y + 'px';
                    element.style.overflow = "hidden";
                    element.style.zIndex = "9999";
                    element.style.pointerEvents = 'none';
                    element.style.opacity = setting.opacity;
                    element.style.fontSize = setting.fontsize;
                    element.style.fontFamily = setting.fontFamily;
                    element.style.color = '#aaa';
                    element.style.textAlign = "center";
                    element.style.width = setting.width + 'px';
                    element.style.height = setting.height + 'px';
                    element.style.display = "block";
                    element.innerHTML = setting.text;
                    fragment.appendChild(element);
                }
            }
            document.body.appendChild(fragment);
        }
    }
}();


