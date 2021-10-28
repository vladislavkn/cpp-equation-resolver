# cpp-equation-resolver
Упрощает и решает уравнения первой и второй степени

## Текущие задачи
- [ ] Добавить изменение знака для переменной
- [ ] Добавить энчантер apply_powers
- [ ] Добавить энчантер apply_multiplications
- [ ] Добавить энчантер simplify
- [ ] Добавить резолвер resolve_power1_0
- [ ] Добавить резолвер resolve_power2_0
- [ ] Добавить резолвер resolve_power2_1
- [ ] Добавить резолвер resolve_power2_1_0
- [ ] Добавить валидатор

## Как это работает? 
#### Сначала строка разбивается на токены, где каждый токен содержит:
- ENUM тип (число, переменная, один из знаков: '+' '-' '*' '^' или пробел)
- FLOAT числовой множитель
- FLOAT показатель степени
При этом числовой множитель могут иметь только числа и переменные, а показатель степени - только переменные

Далее список токенов проходит через ряд энчантеров, упрощающих его структуру. В итоге список преращается в хэш-таблицу, 
где ключом является степень переменной, а значением - ее числовой множитель

#### Последовательно применяются следующие энчантеры:
1. Валидация строки на соответствие формату
2. Применение знаков к числам и переменным (при этом токены знаков удаляются)
3. Применение возведения в степень (при этом знаки степени и показатели степени удаляются)
4. Применение умножения (при этом знак умножения и сомножитель удаляются)
5. Приведение подобных и преобразование в хэш-таблицу

#### После этого, в зависимости от типа уравнения применяются резолверы. Резолверы могут решить следующие уравнения:
- Первой степени, ax+b=0
- Второй степени, ax^2=0, ax^2+b=0, ax^2+bx=0, ax^2+bx+c=0

Резолверы рассчитывают корни уравнения

## Формат входных данных
Доступны для ввода символы '-', '+', '*', '^', 'x', '.', '=' и десятичные цифры.
Число, следующее после знака '^' является показателем степени
