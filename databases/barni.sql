insert into pages (slug, language) values ('main', 'ru');
select * from pages;

INSERT INTO blocks (page_id, type, position, content, styles)
VALUES (
           2,
           'flavors',
           4,
           '{
              "title": "Мягкий бисквит\nс любимой наЧинкой",
              "description": "Шоколад, молоко или банан-йогурт — выбирайте свой вкус Barni\nдля перекуса в любое время!",
              "products": [
                    {
                      "image": "/assets/imgs/flavors/chocolate-flover.png",
                      "name": "Бисквитные пирожные\n«Медвежонок Barni»\nс шоколадной начинкой"
                    },
                    {
                      "image": "/assets/imgs/flavors/banana-flover.png",
                      "name": "Бисквитные пирожные\n«Медвежонок Barni»\nс бананово-йогуртной начинкой"
                    },
                    {
                      "image": "/assets/imgs/flavors/milk-flover.png",
                      "name": "Бисквитные пирожные\n«Медвежонок Barni»\nс молочной начинкой"
                    }
              ]
            }'::jsonb,
           '{}'::jsonb
       );

UPDATE blocks SET type='hero' where id = 2;

select * from blocks;