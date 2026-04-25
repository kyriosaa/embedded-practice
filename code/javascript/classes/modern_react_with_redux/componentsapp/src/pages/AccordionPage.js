import Accordion from "../components/Accordion";

function AccordionPage() {
  const items = [
    {
      id: "asdf",
      label: "Can I use React on a project?",
      content:
        "You can use React on any project you want. You can use React on any project you want. You can use React on any project you want.",
    },
    {
      id: "abcd",
      label: "Can I use JavaScript on a project?",
      content:
        "You can use JavaScript on any project you want. You can use JavaScript on any project you want. You can use JavaScript on any project you want.",
    },
    {
      id: "1234",
      label: "Can I use CSS on a project?",
      content:
        "You can use CSS on any project you want. You can use CSS on any project you want. You can use CSS on any project you want.",
    },
  ];

  return <Accordion items={items} />;
}

export default AccordionPage;
